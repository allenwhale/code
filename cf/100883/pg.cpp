#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll ext_gcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b!=0ll){
        d=ext_gcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else x=1ll,y=0ll;
    return d;
}
ll mod_inverse(ll n, ll p){
    ll x, y;
    ll d = ext_gcd(n, p, x, y);
    return (p+x%p) % p;
}

ll fact(ll n){
    ll res = 1;
    for(ll i=1;i<=n;i++){
        res = (res * i) % MOD;
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d%d", &N, &M);
        ll a = fact(N+M), b = fact(N), c = fact(M);
        a = (a * mod_inverse(b, MOD)) % MOD;
        a = (a * mod_inverse(c, MOD)) % MOD;
        printf("%d\n", (int)a);
    }
    return 0;
}
