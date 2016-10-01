#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x, ll mod){
    return ((x * x) % mod + 1) % mod;
}
ll pow_mod(ll x, ll n, ll mod){
    ll res = 1;
    while(n){
        if(n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
ll PollardRho(ll n){
    if(!(n&1)) return 2;
    while(true){
        ll y = 2, x = rand() % (n-1) + 1, res = 1;
        for(int sz=2;res==1;sz<<=1){
            for(int i=0;i<sz&&res==1;i++){
                x = f(x, n);
                res = __gcd(abs(x - y), n);
            }
            y = x;
        }
        if(res != 1 && res != n) return res;
    }
}
bool PrimeTest(ll a, ll n, ll u, int t) {
    ll x = pow_mod(a, u, n);
    for(int i=0;i<t;i++){
        ll nx = pow_mod(x, 2, n);
        if(nx == 1 && x != 1 && x != n - 1)
            return true;
        x = nx;
    }
    return x != 1;
}
bool MillerRabin(ll n){
    if(n == 2 || n == 3) return true;
    if(n < 2 || !(n & 1)) return false;
    ll u = n - 1, t = 0;
    while(!(u&1))u >>= 1, t++;
    vector<ll> a ;
    a.push_back(2);
    a.push_back(7);
    a.push_back(61);
    for(int i=0;i<(int)a.size();i++){
        ll x = a[i];
        if(x % n && PrimeTest(x % n, n, u, t))
            return false;
    }
    return true;
}
ll Solve(ll n, ll m){
    //printf(" %lld %lld\n", n, m);
    if(__gcd(m, n) > 1)
        return 0;
    if(m == 1)return 1;
    if(m == 2){
        if(n % 8 == 1 || n % 8 == 7)
            return 1;
        if(n % 8 == 3 || n % 8 == 5)
            return -1;
    }
    if(m >= n)
        return Solve(n, m % n);
    if((m & 1) == 0){
        ll r = Solve(n, 2), res = 1;
        while((m & 1) == 0){
            res *= r;
            m >>= 1;
        }
        if(m == 1)
            return res;
        return res * Solve(n, m);
    }
    //puts("mill");
    if(m != 1 && MillerRabin(m) == false){
        ll m1 = PollardRho(m), m2 = m / m1;
        //puts("pol");
        return Solve(n, m1) * Solve(n, m2);
    }
    if(n % 4 == 3 && m % 4 == 3)
        return -Solve(m, n);
    return Solve(m, n);

}
int main(){
    int N, M;
    while(~scanf("%d", &N) && N){
        scanf("%d", &M);
        printf("%lld\n", Solve(M, N));
    }
}
