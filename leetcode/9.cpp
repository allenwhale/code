#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            string s = to_string(x);
            for(int i = 0 ; i < (int)s.length() / 2 ; i++)
                if(s[i] != s[s.length() - 1 - i])
                    return false;
            return true;
        }
};

int main(){
    return 0;
}
