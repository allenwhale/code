#include <bits/stdc++.h>
using namespace std;

const string mp[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};
class Solution {
    public:
        void dfs(vector<string> &ans, const string &digits, int idx, string now){
            if(idx == (int)digits.size()){
                ans.push_back(now);
                return;
            }
            for(auto x : mp[digits[idx] - '0'])
                dfs(ans, digits, idx + 1, now + x);
        }
        vector<string> letterCombinations(string digits) {
            if(digits == "")return {};
            vector<string> ans;
            dfs(ans, digits, 0, "");
            return ans;
        }
};

int main(){
    return 0;
}
