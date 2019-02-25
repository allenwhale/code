#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[3];
int main(){
    vector<int> xs, ys;
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
        xs.push_back(p[i].first);
        ys.push_back(p[i].second);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int mx = xs[1], my = ys[1];
    set<pair<int, int> > ps;
    for (int i = 0; i < 3; i++) {
        int stx = (p[i].first - mx), sty = (p[i].second - my);
        if (stx) stx /= -abs(stx);
        if (sty) sty /= -abs(sty);
        for (int x = p[i].first; x != mx + stx; x += stx) {
            ps.insert({ x, p[i].second });
        }
        for (int y = p[i].second; y != my + sty; y += sty) {
            ps.insert({ mx, y });
        }
    }
    printf("%d\n", ps.size());
    for (auto ansp:ps) {
        printf("%d %d\n", ansp.first, ansp.second);
    }
    return 0;
}
