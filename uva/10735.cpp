#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define foreach(i,x) \
    for(__typeof(x.begin()) it=x.begin(),ed=x.end();it!=ed;it++)
#define SIZE(x) ((int)x.size())
using namespace std;
#define MAXN 110
#define source 0
#define target 105
#define MS(x,v) memset(x,v,sizeof(x))
struct edge
{
    int to,c,rev;
    edge(){}
    edge(int _t,int _c=0,int _r=0)
    {
        to=_t,c=_c,rev=_r;
    }
};
vector<edge>vc[MAXN];
vector<edge>vc2[MAXN];
vector<int>E;
int N,M,d[MAXN],du[MAXN],eid;
bool vis[MAXN],evis[510];
void addedge(int a,int b,int c)
{
    vc[a].push_back(edge(b,c,SIZE(vc[b])));
    vc[b].push_back(edge(a,0,SIZE(vc[a])-1));
}
int BFS()
{
    MS(d,0);
    MS(vis,false);
    queue<int>q;
    q.push(source);
    vis[source]=true;
    d[source]=0;
    while(!q.empty())
    {
        int tmp=q.front();q.pop();
        foreach(it,vc[tmp])
        {
            if(it->c>0&&vis[it->to]==false)
            {
                vis[it->to]=true;
                d[it->to]=d[tmp]+1;
                if(it->to==target)return d[target];
                q.push(it->to);
            }
        }
    }
    return -1;
}
int DFS(int x,int f)
{
    if(x==target)return f;
    if(vis[x])return 0;
    vis[x]=true;
    foreach(it,vc[x])
    {
        if(d[x]+1==d[it->to]&&vis[it->to]==0&&it->c>0)
        {
            int flow=DFS(it->to,min(f,it->c));
            if(flow)
            {
                vc[it->to][it->rev].c+=flow;
                vc[x][vc[it->to][it->rev].rev].c-=flow;
                return flow;
            }
        }
    }
    return 0;
}
int Dinic()
{
    int flow=0;
    while(BFS()!=-1)
    {
        //printf("flow %d\n",flow);
        int f;
        while(MS(vis,false),f=DFS(source,0x3f3f3f3f))flow+=f;
    }
    return flow;
}
void dfs(int x)
{
    foreach(it,vc2[x])
    {
        if(evis[it->c])continue;
        evis[it->c]=true;
        dfs(it->to);
    }
    E.push_back(x);
}
void init()
{
    for(int i=0;i<MAXN;i++)vc[i].clear(),vc2[i].clear();
    E.clear();
    eid=0;
    MS(du,0);
}
int main()
{
    int _T;scanf("%d",&_T);
    while(_T--)
    {
        
        scanf("%d %d",&N,&M);
        init();
        for(int i=0;i<M;i++)
        {
            int a,b;char c;
            scanf("%d %d %c",&a,&b,&c);
            du[a]++;du[b]--;
            if(c=='U')addedge(a,b,1);
            else if(c=='D')vc2[a].push_back(edge(b,eid++));
        }
        bool tf=true;
        int sum=0;
        for(int i=1;tf&&i<=N;i++)
        {
            if(du[i]%2)tf=false;
            du[i]/=2;
            if(du[i]>0)
            {
                sum+=du[i];
                addedge(source,i,du[i]);
            }
            else
            {
                addedge(i,target,-du[i]);
            }
        }
        //printf("%d\n",tf);
        if(tf)tf=(sum==Dinic());
        //puts("dinic");
        if(!tf)
        {
            puts("No euler circuit exist");
            if(_T)puts("");
            continue;
        }
        for(int i=1;i<=N;i++)
        {
            foreach(it,vc[i])
            {
                if(it->to>N||it->to==0)continue;
                if(it->c)vc2[i].push_back(edge(it->to,eid++));
            }
        }
        MS(evis,false);
        dfs(1);
        for(vector<int>::iterator it=E.end()-1;it!=E.begin();it--)
        {
            printf("%d ",*it);
        }
        printf("%d\n",E[0]);
        if(_T)puts("");
    }
}
