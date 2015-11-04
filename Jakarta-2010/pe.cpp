#include <bits/stdc++.h>
using namespace std;
vector<int> vc[500010];
int lca[50010][18];
int din[50010], dout[50010];
int dep;
int v[50010];
void dfs(int x,int p){
    din[x]=dep++;
    lca[x][0]=p;
    for(int i=1;i<18;i++){
        lca[x][i]=lca[lca[x][i-1]][i-1];
    }
    for(int i=0;i<(int)vc[x].size();i++){
        int v=vc[x][i];
        if(v==p)continue;
        dfs(v,x);
    }
    dout[x]=dep++;
}
bool ancestor(int x, int y){
    return din[x]<=din[y]&&dout[x]>=dout[y];
}
int LCA(int x,int y){
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--){
        if(!ancestor(lca[x][i], y))
            x=lca[x][i];
    }
    return lca[x][0];
}
void dfs2(int x,int p){
    for(int i=0;i<(int)vc[x].size();i++){
        int u=vc[x][i];
        if(u==p)continue;
        dfs2(u,x);
        v[x]+=v[u];
    }
}
int Solve(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<=N;i++){
        vc[i].clear();
        v[i]=0;
    }
    for(int i=0;i<N-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    vc[N].push_back(0);
    vc[0].push_back(N);
    dfs(N,N);
    int Q;
    scanf("%d",&Q);
    while(Q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int l=LCA(a,b);
        if(a==b){
            v[a]+=c;
            v[lca[a][0]]-=c;
        }else if(l==a){
            v[b]+=c;
            v[lca[l][0]]-=c;
        }else if(l==b){
            v[a]+=c;
            v[lca[l][0]]-=c;
        }else{
            v[a]+=c;
            v[b]+=c;
            v[l]-=c;
            v[lca[l][0]]-=c;
        }
    }
    dfs2(N,N);
    for(int i=0;i<N;i++)
        printf("%d\n",v[i]);
}
int main(){
    int T, t=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n", t++);
        Solve();
    }
    return 0;
}
