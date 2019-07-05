#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
char s[1000010];
ll pow2(int x) {
    ll res = 1, t = 2;
    while (x) {
        if (x & 1)
            res = (res * t) % MOD;
        t = (t * t) % MOD;
        x >>= 1;
    }
    return res;
}
void Solve() {
    int N, K;
    scanf("%d%d", &N, &K);
    scanf("%s", s);
    int B = 0, mn = 0;
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] == 'B')
            B++;
        else
            B--;
        if (B - mn > K) {
            B -= 2;
            ans = (ans + pow2(i + 1)) % MOD;
        }
        mn = min(mn, B);
    }
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
