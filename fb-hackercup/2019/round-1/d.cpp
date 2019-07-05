#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    mset;
void Solve() {
    vector<pair<ll, ll>> cods;
    int N, H, V;
    scanf("%d%d%d", &N, &H, &V);
    ll x1, x2, Ax, Bx, Cx, Dx;
    ll y1, y2, Ay, By, Cy, Dy;
    scanf("%lld%lld%lld%lld%lld%lld", &x1, &x2, &Ax, &Bx, &Cx, &Dx);
    scanf("%lld%lld%lld%lld%lld%lld", &y1, &y2, &Ay, &By, &Cy, &Dy);
    if (H + V < N) {
        printf("-1\n");
        return;
    }
    cods.push_back({x1, y1});
    cods.push_back({x2, y2});
    for (int i = 2; i < N; i++) {
        ll x = (Ax * cods[i - 2].first + Bx * cods[i - 1].first + Cx) % Dx + 1;
        ll y =
            (Ay * cods[i - 2].second + By * cods[i - 1].second + Cy) % Dy + 1;
        cods.push_back({x, y});
    }
    ll ans = LLONG_MAX;
    for (int k = 0; k < 2; k++) {
        sort(cods.begin(), cods.end());
        mset s1;
        multiset<ll> s2;
        for (auto &xy : cods) {
            s2.insert(xy.second);
        }
        for (int i = 0; i < (int)cods.size(); i++) {
            s1.insert(cods[i].second);
            s2.erase(s2.find(cods[i].second));
            if (N - i - 1 > V)
                continue;
            ll r = s2.size() ? *s2.rbegin() : 0;
            if (i + 1 <= H) {
                ans = min(ans, cods[i].first + r);
            } else {
                ans =
                    min(ans, cods[i].first +
                                 max(*s1.find_by_order(s1.size() - H - 1), r));
            }
        }
        swap(H, V);
        for (int i = 0; i < N; i++)
            swap(cods[i].first, cods[i].second);
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
