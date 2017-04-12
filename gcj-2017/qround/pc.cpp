#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> Solve(ll N, ll K) {
    ll c = 0, b = 1;
    while(c + b < K) c += b, b <<= 1;
    N -= c, K -= c;
    ll r = N - N / b * b;
    if(K <= r) N = N / b + 1;
    else N = N / b;
    return {N / 2, (N - 1) / 2};
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1 ; t <= T ; t++) {
        ll N, K;
        scanf("%lld%lld", &N, &K);
        auto ans = Solve(N, K);
        printf("Case #%d: %lld %lld\n", t, ans.first, ans.second);
    }
    return 0;
}
