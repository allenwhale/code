#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#define foreach(i,x) \
    for(__typeof(x.begin()) it=x.begin(),ed=x.end();it!=ed;it++)
#define MAXN 15
#define SIZE(x) ((int)x.size())
using namespace std;
struct edge
{
    int to,c,rev;
    edge(int _t,int _c,int _r)
    {
        to=_t;c=_c;rev=_r;
    }
    edge(){}
};
vector<edge>vc[MAXN+100];
int N,M,num[MAXN][30];
void addedge(int a,int b,int c)
{
    vc[a].push_back(edge(b,c,SIZE(vc[b])));
    vc[b].push_back(edge(a,0,SIZE(vc[a])-1));
}

/*
source 0
target MAXN+50
BOB 1~30
people 31~
*/
#define source 0
#define target MAXN+50
#define BOB 0
#define PEO 30
int d[MAXN+100];
bool vis[MAXN+100];
int BFS()
{
    memset(vis,false,sizeof(vis));
    memset(d,0,sizeof(d));
    queue<int>q;
    vis[source]=true;
    d[source]=0;
    q.push(source);
    while(!q.empty())
    {
        int tmp=q.front();
        //printf("%d\n",tmp);
        q.pop();
        foreach(it,vc[tmp])
        {
            //printf(" %d %d\n",it->to,it->c);
            if(vis[it->to]==false&&it->c>0)
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
        if(vis[it->to]==false&&it->c>0&&d[x]+1==d[it->to])
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
    int tmp;
    while((tmp=BFS())!=-1)
    {
        //printf("BFS %d\n",tmp);
        int f;
        while(memset(vis,false,sizeof(vis)),f=DFS(source,0x3f3f3f3f))flow+=f;
    }
    return flow;
}
void init()
{
    memset(num,0,sizeof(num));
    for(int i=0;i<MAXN+100;i++)vc[i].clear();
    vc[target].clear();
}
int main()
{
    int _T;
    scanf("%d",&_T);
    int T=1;
    while(_T--)
    {
        scanf("%d %d",&N,&M);
        init();
        for(int i=0;i<N;i++)
        {
            int tmp;scanf("%d",&tmp);
            for(int j=0;j<tmp;j++)
            {
                int idx;scanf("%d",&idx);
                num[i][idx]++;
            }
        }
        for(int i=1;i<=M;i++)
        {
            addedge(source,BOB+i,num[0][i]);
            addedge(BOB+i,target,1);
        }
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(num[i][j]==0)
                {
                    addedge(BOB+j,PEO+i,1);
                }
                else if(num[i][j]>1)
                {
                    addedge(PEO+i,BOB+j,num[i][j]-1);
                }
            }
        }
        int ans=Dinic();
        printf("Case #%d: %d\n",T++,ans);
    }
}
