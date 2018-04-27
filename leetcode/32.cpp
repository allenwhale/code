#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0) return 0;
        vector<int> dp(s.length()); 
        int ans = dp[1] = s[0] == '(' && s[1] == ')' ? 2 : 0;
        for(int i = 2 ; i < (int)s.length() ; i++){
            if(s[i] == ')' && s[i - 1] == '('){
                dp[i] = dp[i - 2] + 2;
            }else if(s[i] == ')' && s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){
                dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    printf("%d\n", sol.longestValidParentheses("()(())"));
    return 0;
}
