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
    pq.push({1, 0});
    while(!pq.empty()){
        PI now = pq.top(); pq.pop();
        if(now.s > dis[now.f]) continue;
        if(now.f == N)break;
        for(PI e: vc[now.f]){
            if(dis[e.f] > dis[now.f] + e.s){
                dis[e.f] = dis[now.f] + e.s;
                pre[e.f] = now.f;
                pq.push({e.f, dis[e.f]});
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
