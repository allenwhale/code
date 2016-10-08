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
ll F[100010];
int zero[100010];
ll get(int l, int r){
    return (F[r] * mod_inverse(F[l - 1], MOD)) % MOD;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        zero[0] = 0;
        F[0] = 1;
        int N, M;
        scanf("%d%d", &N, &M);
        for(int i=1;i<=N;i++){
            ll f;
            scanf("%lld", &f);
            if(f == 0){
                F[i] = F[i - 1];
                zero[i] = zero[i - 1] + 1;
            }else{
                F[i] = (F[i - 1] * f) % MOD;
                zero[i] = zero[i - 1];
            }
        }
        while(M--){
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            if((zero[l2 - 1] - zero[l1 - 1]) > 0 || (zero[r1] - zero[r2]) > 0){
                printf("0\n");
            }else{
                ll d1 = get(l1 ,r1), d2 = get(l2, r2);
                printf("%lld\n", (d1 * mod_inverse(d2, MOD)) % MOD);
            }
        }
    }
    return 0;
}
