#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ext_gcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0ll){
		d = ext_gcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else x = 1ll, y = 0ll;
	return d;
}
ll mod_inverse(ll n, ll p){
	ll x, y;
	ll d = ext_gcd(n, p, x, y);
	return (p + x % p) % p;
}
const ll MOD = 1000000009, A = 137, invA = mod_inverse(A, MOD);
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0 || s.length() == 0) return {};
        int wlen = words[0].length(), slen = s.length(), wnum = words.size();
        vector<ll> apow(wlen, 1);
        for(int i = 1 ; i < wlen ; i++)
            apow[i] = (apow[i - 1] * A) % MOD;
        vector<ll> hwords(words.size()), hs(slen);
        ll key = 1;
        for(int i = 0 ; i < (int)words.size() ; i++){
            for(int j = 0 ; j < wlen ; j++){
                hwords[i] += apow[j] * words[i][j];
                hwords[i] %= MOD;
            }
            key *= hwords[i];
            key %= MOD;
        }
        for(int i = 0 ; i < wlen ; i++){
            hs[0] += apow[i] * s[i];
            hs[0] %= MOD;
        }
        for(int i = 1 ; i <= slen - wlen ; i++){
            hs[i] = (hs[i - 1] - s[i - 1]) * invA + apow[wlen - 1] * s[i + wlen - 1];
            hs[i] = (hs[i] % MOD + MOD) % MOD;
        }
        vector<int> ans;
        for(int i = 0 ; i < wlen ; i++){
            int j = i;
            ll nkey = 1;
            while(j < wnum * wlen)
                nkey *= hs[j], nkey %= MOD, j += wlen;
            while(j < slen){
                if(nkey == key)
                    ans.push_back(j - wnum * wlen);
                nkey *= hs[j];
                nkey %= MOD;
                nkey *= mod_inverse(hs[j - wnum * wlen], MOD);
                nkey %= MOD;
                j += wlen;
            }
            if(nkey == key)
                ans.push_back(j - wnum * wlen);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"bar", "foo"};
    //s = "abaababbaba";
    //words = {"ab","ba","ab","ba"};
    //s = "abaababbaba";
    //words = {"ab","ba","ab","ba"};
    auto ans = sol.findSubstring(s, words);
    for(int x : ans)
        printf("%d\n", x);
    return 0;
}
