#include <bits/stdc++.h>
using namespace std;
struct DJS {
    int p[4010];
    void init(int n) {
        for (int i = 0; i <= n; i++)
            p[i] = i;
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int a, int b) { p[find(a)] = find(b); }
};
DJS djs;
bool dp[4010][4010];
int track[4010][4010];
char ans[4010];
void Solve() {
    int N, M;
    scanf("%d%d", &N, &M);
    djs.init(N);
    unordered_map<int, int> odd, even;
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if ((a + b) & 1) {
            odd[(a + b) / 2] = max(odd[(a + b) / 2], (b - a + 1) / 2);
        } else {
            even[(a + b) / 2] = max(even[(a + b) / 2], (b - a) / 2);
        }
    }
    for (auto &kv : odd) {
        for (int i = 0; i < kv.second; i++) {
            djs.merge(kv.first - i, kv.first + 1 + i);
        }
    }
    for (auto &kv : even) {
        for (int i = 0; i < kv.second; i++) {
            djs.merge(kv.first - i - 1, kv.first + 1 + i);
        }
    }
    unordered_map<int, int> groups;
    unordered_map<int, unordered_set<int>> cnt2group;
    for (int i = 1; i <= N; i++)
        groups[djs.find(i)]++;
    memset(dp[0], false, sizeof(dp[0]));
    dp[0][0] = true;
    memset(track, -1, sizeof(track));
    track[0][0] = 0;
    int cnt = 0;
    for (auto &kv : groups) {
        memcpy(dp[cnt + 1], dp[cnt], sizeof(dp[cnt + 1]));
        for (int i = 0; i <= N; i++)
            track[cnt + 1][i] = i;
        // printf("g %d %d\n", kv.first, kv.second);
        cnt2group[kv.second].insert(kv.first);
        for (int i = N - kv.second; i >= 0; i--) {
            if (dp[cnt][i]) {
                dp[cnt + 1][i + kv.second] = true;
                track[cnt + 1][i + kv.second] = i;
            }
        }
        cnt++;
    }
    int ones = N / 2;
    while (dp[cnt][ones] == false)
        ones--;
    // printf("%d\n", ones);
    unordered_set<int> onegorups;
    while (ones) {
        // printf("o %d\n", ones);
        int t = track[cnt][ones];
        // printf("o %d %d\n", ones, t);
        if (ones != t) {
            auto it = cnt2group[ones - t].begin();
            // printf("%p\n", it);
            onegorups.insert(*it);
            // printf("%d\n", *it);
            cnt2group[ones - t].erase(it);
        }
        ones = t;
        cnt--;
    }
    memset(ans, '0', sizeof(ans));
    for (int i = 1; i <= N; i++) {
        int g = djs.find(i);
        if (onegorups.find(g) != onegorups.end())
            ans[i] = '1';
    }
    ans[N + 1] = 0;
    printf("%s\n", ans + 1);
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