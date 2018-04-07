#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll mpow(ll x, ll n){
    ll res = 1;
    while(n){
        if(n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n, m;
    int k;
    scanf("%lld%lld%d", &n, &m, &k);
    if((n & 1) != (m & 1) && k == -1){
        printf("0\n");
        return 0;
    }
    ll ans = mpow(mpow(2, n - 1), m - 1);
    printf("%lld\n", ans);
    return 0;
}
