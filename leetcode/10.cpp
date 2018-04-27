#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            vector<int> newp = {0};
            for(int i = 0 ; i < (int)p.length() ; i++){
                if(i != (int)p.length() - 1 && p[i + 1] == '*')
                    newp.push_back(-p[i]), i++;
                else newp.push_back(p[i]);
            }
            vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
            dp[0][0] = true;
            const char *sptr = s.c_str() - 1;
            for(int j = 1 ; j < (int)newp.size() ; j++){
                dp[0][j] = dp[0][j - 1] && newp[j] < 0;
            }
            for(int i = 1 ; i <= (int)s.length() ; i++){
                for(int j = 1 ; j < (int)newp.size() ; j++){
                    if(newp[j] < 0){
                        dp[i][j] = ((dp[i - 1][j] || dp[i - 1][j - 1]) && (newp[j] == -(int)'.' ? true : sptr[i] == -newp[j])) || dp[i][j - 1];
                    }else{
                        dp[i][j] = newp[j] == '.' ? dp[i - 1][j - 1] : (dp[i - 1][j - 1] && newp[j] == sptr[i]);
                    }
                }
            }
            return dp[s.length()][newp.size() - 1];
        }
};

int main(){
    Solution sol;
    printf("%d\n", sol.isMatch("aa", "a"));
    printf("%d\n", sol.isMatch("aa", "a*"));
    printf("%d\n", sol.isMatch("ab", ".*"));
    printf("%d\n", sol.isMatch("aab", "c*a*b"));
    printf("%d\n", sol.isMatch("mississippi", "mis*is*p*."));
    return 0;
}
