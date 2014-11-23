#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define N 500005
#define INF 999999999
vector<int> s1[N],s2[N];
stack<int> _stack;
queue<int> que;
int pt[N],is[N]={0},val[N]={0},dis[N]={0},in[N]={0};
int dfs_cnt=0,scc_cnt=0,pre[N]={0},sccno[N]={0};
int dfs(int u){
    int i,lowu,lowv;
    lowu=pre[u]=++dfs_cnt;
    _stack.push(u);
    for(i=0;i<s1[u].size();i++){
        int v=s1[u][i];
        if(pre[v]==0){
            lowv=dfs(v);
            lowu=min(lowu,lowv);
        }
        else if(!sccno[v]){
            lowu=min(lowu,pre[v]);
        }
    }
    if(lowu==pre[u]){
        ++scc_cnt;
        while(1){
            int v=_stack.top();
            _stack.pop();
            val[scc_cnt]+=pt[v];
            sccno[v]=scc_cnt;
            if(v==u) break;
        }
    }
    return lowu;
}
int ans=0;
int main(){
    int n,m,i,j,x,y,s,p;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        s1[x].push_back(y);
    }
    for(i=0;i<n;i++){
        scanf("%d",&pt[i]);
    }
    for(i=0;i<n;i++){
        if(pre[i]==0){
            dfs_cnt=0;
            dfs(i);
        }
    }
    scanf("%d%d",&s,&p);
    s--;
    for(i=0;i<p;i++){
        scanf("%d",&x);
        x--;
        is[sccno[x]]=1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<s1[i].size();j++){
            x=i,y=s1[i][j];
            if(sccno[x]!=sccno[y])
                s2[sccno[x]].push_back(sccno[y]);
        }
    }
    memset(dis,-1,sizeof(dis));
    dis[sccno[s]]=val[sccno[s]];
    que.push(sccno[s]);
    in[sccno[s]]=1;
    while(que.size()){
        int u=que.front();
        que.pop();
        in[u]=0;
        for(i=0;i<s2[u].size();i++){
            int v=s2[u][i];
            if(dis[v]<dis[u]+val[v]){
                dis[v]=dis[u]+val[v];
                if(is[v])
                    ans=max(dis[v],ans);
                if(in[v]==0){
                    in[v]=1;
                    que.push(v);
                }
            }
        }
    }
    printf("%d\n",ans);
}
