#include <bits/stdc++.h>
using namespace std;
//I V   X   L   C   D   M
//1 5   10  50  100 500 1000
static constexpr const int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
static constexpr const char *str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
class Solution {
    public:
        string intToRoman(int num) {
            string ans = "";
            for(int i = 0 ; i < 13 ; i++){
                while(num >= val[i]) ans += str[i], num -= val[i];
            }
            return ans;
        }
};

int main(){
    Solution sol;
    cout << sol.intToRoman(1) << endl;
    cout << sol.intToRoman(1234) << endl;
    cout << sol.intToRoman(2345) << endl;
    cout << sol.intToRoman(3456) << endl;
}
