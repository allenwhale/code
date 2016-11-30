#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll check(ll n, ll l){
    ll b = pow((double)n, 1.0 / (l - 1));
    while(n){
        if(n % b != 1)return -1;
        n /= b;
    }
    return b;
}
ll Solve(ll N){
    for(ll i = __lg(N)+1;i>2;i--){
        ll b;
        if((b=check(N, i)) != -1)
            return b;
    }
    return N - 1;
}
bool check2(ll N, ll b){
    while(N){
        if(N % b != 1)return false;
        N /= b;
    }
    return true;
}
ll Solve2(ll N){
    for(int b=2;b<N;b++){
        if(check2(N, b))return b;
    }
    return N-1;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        ll N;
        scanf("%lld", &N);
        printf("Case #%d: %lld\n", t, Solve(N));
    }
    return 0;
}
