#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define sqr(x) ((x) * (x))
#define MOD 1000000007ll
ll Solve(ll r, ll c){
    ll x = min(r, c);
    ll ans1 = x * (r * c + c + r + 1) % MOD
        - (c + r + 2) * ((x * (x + 1)) / 2) % MOD 
        + ((x * (x + 1) * (2 * x + 1)) / 6) % MOD;
    ll ans2 = sqr((x * (x + 1)) / 2) % MOD
        - (c + r + 3) * (x * (x + 1) * (2 * x + 1)) / 6 % MOD
        + (r * c + 2 * r + 2 * c + 3) * ((x * (x + 1)) / 2) % MOD
        - (x) * (c * r + c + r + 1) % MOD;
    if(x <= 1)ans2 = 0;
    return (ans1 + ans2 + MOD) % MOD;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int R, C;
        scanf("%d%d", &R, &C);
        R--, C--;
        printf("Case #%d: %d\n", t, (int)Solve(R, C));
    }
    return 0;
}
