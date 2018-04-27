#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int loop = numRows * 2 - 2;     
        vector<char> res[numRows];
        for(int i = 0 ; i < (int)s.length() ; i++){
            if(i % loop < numRows){
                res[i % loop].push_back(s[i]);
            }else{
                res[loop - (i % loop)].push_back(s[i]);
            }
        }
        string ans = "";
        for(int i = 0 ; i < numRows ; i++)
            for(char x : res[i])
                ans += x;
        return ans;
    }
};

int main(){
    Solution sol;
    auto s = sol.convert("PAYPALISHIRING", 3);
    printf("%s\n", s.c_str());
    
}
