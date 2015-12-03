#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int f[210];
ll d[210];
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &f[i]), f[i]--;

    ll ans = 1, mn = 0;
    for(int i=0;i<N;i++){
        memset(d, -1, sizeof(d));
        int idx = i;
        int cnt = 0;
        while(d[idx] == -1)
            d[idx] = cnt++, idx = f[idx];
        mn = max(mn, d[idx]);
        ll c = cnt - d[idx];
        ans *= c / __gcd(c, ans);
    }
    if(ans < mn) ans *= (mn - 1) / ans + 1;
    printf("%I64d\n", ans);
    return 0;
}
