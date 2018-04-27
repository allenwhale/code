#include <bits/stdc++.h>
using namespace std;

vector<int> zvaule_pali(const string& s1){
	int len1 = s1.size(), len2 = len1 * 2 + 1;
	vector<int> z(len2, 0);
	string s2(len2, '@');
	for(int i=0;i<len2;i++)
		if(i & 1)s2[i] = s1[i / 2];
	z[0] = 1;
	int l = 0, r = 0;
	for(int i=1;i<len2;i++){
		if(i > r){
			l = r = i;
			while(l > 0 && r < len2 - 1 && s2[l - 1] == s2[r + 1])
				l--, r++;
			z[i] = r - l + 1;
		}else{
			z[i] = z[((l + r) & (~1)) - i];
			int nr = i + z[i] / 2;
			if(nr == r){
				l = i * 2 - r;
				while(l > 0 && r < len2 - 1 && s2[l - 1] == s2[r + 1])
					l--, r++;
				z[i] = r - l + 1;
			}else if(nr > r){
				z[i] = (r - i) * 2 + 1;
			}
		}
	}
	return z;
}
class Solution {
public:
    string longestPalindrome(string s) {
        auto zv = zvaule_pali(s); 
        int ans = 0, idx = -1;
        for(int i = 0 ; i < (int)zv.size() ; i++){
            if((zv[i] - 1) / 2 > ans){
                ans = (zv[i] - 1) / 2;
                idx = i / 2 - ans / 2;
            }
        }
        return s.substr(idx, ans);
    }
};

int main(){
    Solution sol;
    auto s = sol.longestPalindrome("cbbd");
    printf("%s\n", s.c_str());
    s = sol.longestPalindrome("a");
    printf("%s\n", s.c_str());
    s = sol.longestPalindrome("babad");
    printf("%s\n", s.c_str());
}
