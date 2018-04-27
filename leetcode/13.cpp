#include <bits/stdc++.h>
using namespace std;

//I V   X   L   C   D   M
//1 5   10  50  100 500 1000

unordered_map<char, int> convert = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

class Solution {
    public:
        int romanToInt(string s) {
            int ans = 0;
            for(int i = 0 ; i < (int)s.length() ; i++){
                if(i != (int)s.length() - 1 && convert[s[i]] < convert[s[i + 1]])
                    ans -= convert[s[i]];
                else
                    ans += convert[s[i]];
            }
            return ans;
        }
};

int main(){
    return 0;
}
