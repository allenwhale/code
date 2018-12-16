#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll MOD = 1000000007;
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
void Solve(){
    int N, M;

    scanf("%d%d", &N, &M);
    ll ans = 0;
    ll c = 1, f = 1, p = 1;
    for (int i = 1; i <= 2 * N; i++) {
        f *= (ll)i;
        f %= MOD;
    }
    ll t = 1;
    for (int k = 0; k <= M; k++) {
        ans += (t * (((c * p) % MOD) * f) % MOD) % MOD;
        ans = (ans + MOD) % MOD;
		// printf("=%lld,%lld,%lld,%lld\n", (long long)c, (long long)p, (long long)f, (long long)((c * p) % MOD * f) % MOD);
        c = (((c * (M - k)) % MOD) * mod_inverse(k + 1, MOD)) % MOD;
        f = (f * mod_inverse(2 * N - k, MOD)) % MOD;
        p = (p * 2) % MOD;
        t *= -1;
    }
    printf("%lld\n", (long long)ans);
}
int main(){
    int T;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
