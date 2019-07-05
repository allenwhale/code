#include <bits/stdc++.h>
using namespace std;
int dis[55][55];
void Solve() {
    memset(dis, 0x3f, sizeof(dis));
    int N, M;
    scanf("%d%d", &N, &M);
    vector<array<int, 3>> ed;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        ed.push_back({a, b, c});
        dis[a][b] = dis[b][a] = c;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        if (dis[ed[i][0]][ed[i][1]] != ed[i][2]) {
            printf("Impossible\n");
            return;
        }
    }
    printf("%d\n", M);
    for (auto &e : ed) {
        printf("%d %d %d\n", e[0] + 1, e[1] + 1, e[2]);
    }
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