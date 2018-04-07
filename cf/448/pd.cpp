#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007ll
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
ll frac[1000010], i_frac[1000010];
char s[2][1000010];
int cnt[30];
int len;
ll compute(int idx){
    int wcnt[30];
    memcpy(wcnt, cnt, sizeof(cnt));
    ll res = 0;
    for(int i = 0 ; i < len ; i++){
        ll tmp = frac[len - i - 1];
        for(int j = 0 ; j < 26 ; j++)
            tmp = (tmp * i_frac[wcnt[j]]) % MOD;
        for(int j = 0 ; j < s[idx][i] - 'a' ; j++){
            if(wcnt[j]){
                ll ttmp = tmp;
                ttmp = (ttmp * frac[wcnt[j]]) % MOD;
                ttmp = (ttmp * i_frac[wcnt[j] - 1]) % MOD;
                res = (res + ttmp) % MOD;
            }
        }
        if(wcnt[s[idx][i] - 'a']){
            wcnt[s[idx][i] - 'a']--;
            if(i == len - 1)res++;
        }else{
            break;
        }
    }
    return res;
}
int main(){
    i_frac[0] = frac[0] = 1;
    for(int i = 1 ; i < 1000010 ; i++){
        frac[i] = (frac[i - 1] * i) % MOD;
        i_frac[i] = mod_inverse(frac[i], MOD);
    }
    scanf("%s%s", s[0], s[1]);
    if(strcmp(s[0], s[1]) >= 0){
        printf("%d\n", 0);
        return 0;
    }
    len = strlen(s[0]);
    for(int i = 0 ; i < len ; i++)
        cnt[s[0][i] - 'a']++;
    ll ans = (compute(1) - compute(0) + MOD) % MOD;
    for(int i = 0 ; i < len ; i++)
        cnt[s[1][i] - 'a']--;
    bool same = true;
    for(int i = 0 ; i < 26 ; i++)
        if(cnt[i])
            same = false;
    if(same) ans = (ans - 1 + MOD) % MOD;
    printf("%lld\n", max(ans, 0ll));
    return 0;
}
