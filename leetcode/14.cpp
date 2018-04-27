#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 0) return "";
            string ans = "";
            for(int i = 0 ; i < (int)strs[0].length() ; i++){
                for(int j = 1 ; j < (int)strs.size() ; j++){
                    if(i >= (int)strs[j].length() || strs[j][i] != strs[0][i]) return ans;
                }
                ans += strs[0][i];
            }
            return ans;
        }
};
int main(){
    return 0;
}
