#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, int>> vc[10010];
int dist[10010];
bool vis[10010];
int main(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vc[a].push_back({b, c});
        vc[b].push_back({a, c});
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(now.first < dist[now.second])continue;
        for(auto e : vc[now.second]){
            if(dist[e.first] > dist[now.second] + e.second){
                dist[e.first] = dist[now.second] + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }
    queue<int> q;
    q.push(N - 1);
    int ans = 0;
    memset(vis, false, sizeof(vis));
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(vis[now]) continue;
        vis[now] = true;
        for(auto e : vc[now]){
            if(dist[now] - e.second == dist[e.first]){
                ans += e.second;
                q.push(e.first);
            }
        }
    }
    printf("%d\n", ans * 2);
    return 0;
}
