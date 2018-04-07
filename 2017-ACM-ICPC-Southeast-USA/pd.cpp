#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
deque<pair<int, int>> h[2010], v[2010];
void update(deque<pair<int, int>> &q, int pos, int v){
    while(q.size() && q.back().second >= v)
        q.pop_back();
    q.push_back({pos, v});
}
void clean(deque<pair<int, int>> &q, int pos){
    while(q.size() && q.front().first < pos)
        q.pop_front();
}
int getMin(deque<pair<int, int>> &q){
    return q.size() ? q.front().second : INF;
}
char mp[2010][2010];
int dp[2010][2010];
int main(){
    int N, K;
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d%d", &N, &K);
    for(int i = 0 ; i < N ; i++)
        scanf("%s", mp[i]);
    dp[0][0] = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            clean(h[i], j - K);
            clean(v[j], i - K);
            if(mp[i][j] != '#'){
                dp[i][j] = min(dp[i][j], getMin(h[i]) + 1);
                dp[i][j] = min(dp[i][j], getMin(v[j]) + 1);
            }
            update(h[i], j, dp[i][j]);
            update(v[j], i, dp[i][j]);
        }
    }
    if(dp[N - 1][N - 1] >= INF)
        printf("-1\n");
    else printf("%d\n", dp[N - 1][N - 1]);
    return 0;
}
