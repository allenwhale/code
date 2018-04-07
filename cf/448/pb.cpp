#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010];
int main(){
    int N, x, k;
    scanf("%d%d%d", &N, &x, &k);
    for(int i = 0 ; i < N ; i++)
        scanf("%lld", &a[i]);
    a[N] = INT_MIN;
    a[N + 1] = LLONG_MAX;
    sort(a, a + N + 2);
    ll ans = 0;
    for(int i = 1 ; i <= N ; i++){
        ll kk = (a[i] - 1) / x + k;
        ll top = (kk + 1) * x - 1;
        ll low = max(kk * x, a[i]);
        int pos_top = upper_bound(a, a + N + 2, top) - a - 1;
        int pos_low = lower_bound(a, a + N + 2, low) - a;
        ans += max(0, pos_top - pos_low + 1);
    }
    printf("%lld\n", ans);
    return 0;
}
