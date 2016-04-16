#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int convert(ll N){
    bool v[10] = {false};
    while(N){
        v[N % 10] = true;
        N /= 10;
    }
    int res = 0;
    for(int i=9;i>=0;i--)
        res = (res << 1) | (int)v[i];
    return res;
}
ll Solve(){
    ll N, n;
    scanf("%lld", &N);
    if(N == 0)return -1;
    n = N;
    int used = 0;
    while(true){
        used |= convert(N);
        if(used == (1<<10) - 1)break;
        N += n;
    }
    return N;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        ll ans = Solve();
        printf("Case #%d: ", t);
        if(ans == -1)puts("INSOMNIA");
        else printf("%lld\n", ans);
    }
    return 0;
}
