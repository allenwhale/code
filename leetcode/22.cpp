#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(vector<string> &ans, int n, int val, string now){
            if(n == 0 && val == 0){
                ans.push_back(now);
                return;
            }
            if(n == 0)dfs(ans, n, val - 1, now + ')');
            else if(val == 0)dfs(ans, n - 1, val + 1, now + '(');
            else{
                dfs(ans, n, val - 1, now + ')');
                dfs(ans, n - 1, val + 1, now + '(');
            }
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            dfs(ans, n, 0, "");
            return ans;
        }
};

int main(){
    Solution sol;
    auto ans = sol.generateParenthesis(3);
    for(auto &x : ans)
        cout << x << endl;
    return 0;
}
