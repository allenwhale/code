#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353ll;
ll ext_gcd(ll a, ll b, ll &x, ll &y){
    ll d = a;

    if (b != 0ll) {
        d = ext_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else x = 1ll, y = 0ll;
    return d;
}
ll mod_inverse(ll n, ll p){
    ll x, y;
    ll d = ext_gcd(n, p, x, y);

    return (p + x % p) % p;
}
ll f(ll n){
    ll res = 1;

    for (int i = 1; i <= n; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}
ll p(ll x, ll n){
    ll res = 1;

    while (n--) {
        res = (res * x) % MOD;
    }
    return res;
}
int N, M, K;
int main() {
    scanf("%d%d%d", &N, &M, &K);
	// if (M == 1 && K != 0) {
	//     printf("0\n");
	//     return 0;
	// }
    ll ans = 1;
    if (K > 0) {
        ans = f(N - 1);
        ans = (ans * mod_inverse(f(N - 1 - K), MOD)) % MOD;
        ans = (ans * mod_inverse(f(K), MOD)) % MOD;
    }
    ans = (ans * M) % MOD;
    if (K > 0) {
        ans = (ans * p(M - 1, K)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
