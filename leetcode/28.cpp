#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)return 0;
        vector<int> fail(needle.length());
        for(int i = 1, j = fail[0] = -1 ; i < (int)needle.length() ; i++){
            while(j != -1 && needle[j + 1] != needle[i])
                j = fail[j];
            if(needle[j + 1] == needle[i])j++;
            fail[i] = j;
        }
        for(int i = 0, j = -1 ; i < (int)haystack.length() ; i++){
            while(j != -1 && needle[j + 1] != haystack[i])
                j = fail[j];
            if(needle[j + 1] == haystack[i])j++;
            if(j == (int)needle.length() - 1)
                return i - j;
        }
        return -1;
    }
};

int main(){
    return 0;
}
