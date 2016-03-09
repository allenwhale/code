#include <bits/stdc++.h>
using namespace std;
int N, M, mp[110][110], p[110];
int start, target;
typedef pair<int, int> PI;
vector<PI> vc[110];
#define f first
#define s second
int dist[110], pre[110];
deque<int> path;
int BFS(int s, int t){
    priority_queue<PI, vector<PI>, greater<PI>> pq;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        PI now = pq.top(); pq.pop();
        //printf("%d %d\n", now.f, now.s);
        if(now.f > dist[now.s])continue;
        if(t == now.s)break;
        for(PI e: vc[now.s]){
            if(dist[e.f] > e.s+now.f){
                dist[e.f] = e.s+now.f;
                pre[e.f] = now.s;
                pq.push({dist[e.f], e.f});
            }
        }
    }
    path.clear();
    for(int i=t;i!=s;i=pre[i]){
        path.push_front(i);
    }
    path.push_front(s);
    return dist[t];
}
bool Solve(){
    scanf("%d", &N);
    if(N == 0)return false;
    for(int i=0;i<N;i++)
        vc[i].clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int w;
            scanf("%d", &w);
            if(w != 0) vc[i].push_back({j, w});
        }
    }
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        scanf("%d", &p[i]);
    }
    BFS(p[0], p[M-1]);
    int ans = 0;
    for(int i=1;i<M;i++){
        //printf("path: ");
        //for(int x: path)
        //printf("%d ", x);
        //puts("");
        if(p[i] != path[1]){
            //printf("x %d %d %d\n", i, p[i], path[1]);
            BFS(p[i], p[M-1]);
            ans++;
        }
        else path.pop_front();
    }
    static int cas = 1;
    printf("Case %d: %d\n", cas++, ans);
    return true;
}
int main(){
    while(Solve());
    return 0;
}
