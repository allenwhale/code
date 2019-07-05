#include <bits/stdc++.h>
using namespace std;
struct Dinic {
    struct Edge {
        int v1, v2, f, c;
    };
    int N;
    vector<vector<int>> vc;
    vector<Edge> E;
    vector<int> dep;

    Dinic(int n = 0)
        : N(n), vc(vector<vector<int>>(N + 1)), dep(vector<int>(N + 1)) {}
    void add_edge(int a, int b, int c) {
        vc[a].push_back(E.size());
        E.push_back({a, b, c, c});
        vc[b].push_back(E.size());
        E.push_back({b, a, 0, c});
    }
    int Bfs(int s, int t) {
        fill(dep.begin(), dep.end(), -1);
        dep[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < (int)vc[v].size(); i++) {
                Edge e = E[vc[v][i]];
                if (e.f > 0 && dep[e.v2] == -1) {
                    dep[e.v2] = dep[v] + 1;
                    q.push(e.v2);
                }
            }
        }
        return dep[t];
    }
    int Dfs(int x, int df, int t) {
        if (x == t)
            return df;
        int res = 0;
        for (int i = 0; i < (int)vc[x].size(); i++) {
            Edge &e = E[vc[x][i]];
            if (e.f > 0 && dep[e.v2] == dep[x] + 1) {
                int f = Dfs(e.v2, min(df, e.f), t);
                e.f -= f;
                df -= f;
                res += f;
                E[vc[x][i] ^ 1].f += f;
                if (df == 0)
                    return res;
            }
        }
        if (res == 0)
            dep[x] = -1;
        return res;
    }
    int Solve(int s, int t) {
        int flow = 0;
        while (Bfs(s, t) != -1) {
            flow += Dfs(s, 0x3f3f3f3f, t);
        }
        return flow;
    }
};

void Solve() {
    int N, H;
    scanf("%d%d", &N, &H);
    Dinic dinic(N + 2);
    int S = N, T = N + 1;
    vector<array<int, 3>> ladders;
    for (int i = 0; i < N; i++) {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        if (a > b)
            swap(a, b);
        ladders.push_back({x, a, b});
    }
    sort(ladders.begin(), ladders.end());
    for (int i = 0; i < (int)ladders.size(); i++) {
        if (ladders[i][1] == 0)
            dinic.add_edge(S, i, 0x3f3f3f3f);
        if (ladders[i][2] == H)
            dinic.add_edge(i, T, 0x3f3f3f3f);
    }
    for (int i = 0; i < (int)ladders.size(); i++) {
        vector<array<int, 3>> segs = {ladders[i]};
        for (int j = i + 1; j < (int)ladders.size(); j++) {
            if (ladders[i][0] == ladders[j][0]) {
                if (ladders[i][2] >= ladders[j][1]) {
                    dinic.add_edge(i, j, 0x3f3f3f3f);
                    dinic.add_edge(j, i, 0x3f3f3f3f);
                }
                continue;
            }
            vector<array<int, 3>> new_segs;
            for (auto seg : segs) {
                if (ladders[j][1] > seg[2] || ladders[j][2] < seg[1]) {
                    new_segs.push_back(seg);
                    continue;
                }
                int n_mn = max(seg[1], ladders[j][1]),
                    n_mx = min(seg[2], ladders[j][2]);
                dinic.add_edge(i, j, n_mx - n_mn);
                dinic.add_edge(j, i, n_mx - n_mn);
                if (n_mn == n_mx)
                    new_segs.push_back(seg);
                else if (n_mn == seg[1] && n_mx == seg[2])
                    continue;
                else if (n_mn == seg[1])
                    new_segs.push_back({0, n_mx, seg[2]});
                else if (n_mx == seg[2])
                    new_segs.push_back({0, seg[1], n_mn});
                else {
                    new_segs.push_back({0, seg[1], n_mn});
                    new_segs.push_back({0, n_mx, seg[2]});
                }
            }
            segs = new_segs;
        }
    }
    int ans = dinic.Solve(S, T);
    if (ans < 0x3f3f3f3f)
        printf("%d\n", ans);
    else
        printf("-1\n");
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
