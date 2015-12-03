#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PI;
vector<PI> vc[200010];
int dis[200010], pre[200010];
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vc[a].push_back({b, c});
        vc[b].push_back({a, c});
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    priority_queue<PI, vector<PI>, greater<PI> > pq;
    dis[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        PI now = pq.top(); pq.pop();
        if(now.f > dis[now.s]) continue;
        if(now.s == N)break;
        for(PI e: vc[now.s]){
            if(dis[e.f] > dis[now.s] + e.s){
                dis[e.f] = dis[now.s] + e.s;
                pre[e.f] = now.s;
                pq.push({dis[e.f], e.f});
            }
        } 
    }
    if(dis[N] == 0x3f3f3f3f){
        puts("-1");
        return 0;
    }
    vector<int> ans;
    for(int t=N;~t;t=pre[t])
        ans.push_back(t); 
    reverse(ans.begin(), ans.end());
    for(int x: ans)
        printf("%d ", x);
    puts("");
    return 0;
}
