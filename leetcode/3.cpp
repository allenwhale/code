#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, -1);
        int last = -1, ans = 0;
        for(int i = 0 ; i < (int)s.length() ; i++){
            last = max(last, vis[s[i]]);
            ans = max(ans, i - last);
            vis[s[i]] = i;
        }
        return ans;
    }
};

int main(){
    return 0;
}
