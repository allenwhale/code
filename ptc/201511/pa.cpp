#include <bits/stdc++.h>
using namespace std;
#define MAXN 50010
struct S{
    int t,r,w;
    bool operator < (const S& n)const{
        if(r==n.r)return w<n.w;
        return r<n.r;
    }
    bool operator > (const S& n)const{
        if(r==n.r)return w>n.w;
        return r>n.r;
    }
}dis[MAXN];
vector<S>vc[MAXN];
void Solve(){
    int N,M;
    scanf("%d%d",&N,&M);
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<=N;i++)
        vc[i].clear();
    for(int i=0;i<M;i++){
        int a,b,r,w;
        scanf("%d%d%d%d",&a,&b,&r,&w);
        vc[a].push_back({b,r,w});
        vc[b].push_back({a,r,w});
    }
    dis[0]={0,0,0};
    priority_queue<S,vector<S>, greater<S>>pq;
    pq.push(dis[0]);
    while(!pq.empty()){
        S t=pq.top();
        pq.pop();
        printf("%d %d %d\n", t.t,t.r,t.w);
        if(t.t==N-1){
            break;
        }
        for(S s:vc[t.t]){
            s.r=max(s.r,t.r);
            s.w+=t.w;
            if(s<dis[s.t]){
                dis[s.t]=s;
                pq.push(s);
            }
        }
    }
    if(dis[N-1].r!=0x3f3f3f3f)printf("%d %d\n", dis[N-1].r, dis[N-1].w);
    else printf("-1\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        Solve();
    }
    return 0;
}
