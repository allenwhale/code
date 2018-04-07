#include <bits/stdc++.h>
using namespace std;
int g[1010], d[1010];
int dp[2020][1010];
vector<pair<int, int>> ed[1010];
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int maxDay = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%d%d", &g[i], &d[i]);
        maxDay = max(maxDay, g[i] / d[i] + 1);
    }
    for(int i = 0 ; i < M ; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        ed[a].push_back({b, c});
        ed[b].push_back({a, c});
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0 ; i < 2020 ; i++)
        for(int j = 0 ; j < 1010 ; j++)
            dp[i][j] = INT_MIN;
    dp[0][0] = g[0];
    int ans = 0;
    for(int i = 0 ; i < maxDay ; i++){
        for(int j = 0 ; j < N ; j++){
            for(auto &e : ed[j]){
                dp[i + e.second][e.first] = max(dp[i + e.second][e.first], dp[i][j] + max(0, g[e.first] - d[e.first] * (i + e.second)));
                ans = max(ans, dp[i + e.second][e.first]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
