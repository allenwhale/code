#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef pair<int,PI> PII;
#define w first
#define v1 second.first
#define v2 second.second
const int INF=0x3f3f3f3f;
int N,M;
vector<PII> edge;
int p[510];
bool vis[510]={false};
int find(int x){
    return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b){
    p[find(b)]=find(a);
}
void init(){
    for(int i=0;i<=N;i++)
        p[i]=i;
}
int MST(int ex=-1){
    init();
    int res=0,cnt=0;
    for(int i=0;i<(int)edge.size();i++){
        PII e=edge[i];
        if(i!=ex&&find(e.v1)!=find(e.v2)){
            if(ex==-1)vis[i]=true;
            U(e.v1,e.v2);
            res+=e.w;
            cnt++;
        }
    }
    return cnt!=N-1?INF:res;
}
int main(){
    scanf("%d%d",&N,&M); 
    for(int i=0;i<M;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edge.push_back({w,{a,b}});
    }
    sort(edge.begin(), edge.end());
    int mst=MST();
    int ans=0,cnt=0;
    for(int i=0;i<(int)edge.size();i++){
        if(vis[i]){
            if(MST(i)>mst)
                ans+=edge[i].w,cnt++;
        }
    }
    printf("%d %d\n", cnt,ans);

    return 0;
}
