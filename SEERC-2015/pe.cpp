#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int N, M, B, C, P;
vector<pair<int, int>> ed[MAXN];
int dis[MAXN];
int home_dis[32][32];
vector<int> Point;
void BFS(int s){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[s], s});
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(now.first > dis[now.second])
            continue;
        for(auto e : ed[now.second]){
            if(dis[e.first] > dis[now.second] + e.second){
                dis[e.first] = dis[now.second] + e.second;
                pq.push({dis[e.first], e.first});
            }
        }
    }
}
int dp[1<<15][16][5][16];
int DP(int status, int car, int people, int v){
    if(dp[status][car][people][v] != 0x3f3f3f3f)
        return dp[status][car][people][v];
    if(status == 0)
        return dp[status][car][people][v] = 0;
    if(people != 0){
        dp[status][car][people][v] = min(dp[status][car][people][v], DP(status, car+1, 0, P));
    }
    if(people != 4){
        for(int i=0;i<P;i++){
            if(status & (1<<i)){
                dp[status][car][people][v] = min(dp[status][car][people][v],
                        DP(status ^ (1<<i), car, people+1, i) + (people == 0 ? B : 0) + 
                        home_dis[v][i]);
            }
        }
    }
    return dp[status][car][people][v];
}
int main(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++){
        int d, a, b, c;
        scanf("%d%d%d%d", &d, &a, &b, &c);
        if(d == 1){
            ed[a].push_back({b, c});
        }else if(d == 2){
            ed[a].push_back({b, c});
            ed[b].push_back({a, c});
        }
    }
    scanf("%d%d%d", &B, &C, &P);
    for(int i=0;i<P;i++){
        int x;
        scanf("%d", &x);
        Point.push_back(x);
    }
    Point.push_back(C);
    for(int i = 0 ; i < (int)Point.size() ; i++){
        BFS(Point[i]);
        for(int j = 0 ; j < (int)Point.size() ; j++){
            home_dis[i][j] = dis[Point[j]];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    printf("%d\n", DP((1 << P) - 1, 0, 0, P));
    return 0;
}

