#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#define foreach(i,x) \
    for(__typeof(x.begin()) it=x.begin(),ed=x.end();it!=ed;it++)
#define SIZE(x) ((int)x.size())
#define MS(a,b) memset(a,b,sizeof(a))
using namespace std;
#define MAXN 55
#define source MAXN*MAXN-10
#define target MAXN*MAXN-5
struct edge
{
    int to,c,rev;
    edge(int _t=0,int _c=0,int _r=0)
    {
        to=_t;c=_c;rev=_r;
    }
};
vector<edge>vc[MAXN*MAXN+10];
int W,H,D,F,B;
char s[MAXN][MAXN];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int d[MAXN*MAXN+10];
bool vis[MAXN*MAXN+10];
void addedge(int a,int b,int c)
{
    vc[a].push_back(edge(b,c,SIZE(vc[b])));
    vc[b].push_back(edge(a,0,SIZE(vc[a])-1));
}
int BFS()
{
    MS(d,0);MS(vis,false);
    queue<int>q;
    q.push(source);
    d[source]=0;vis[source]=true;
    while(!q.empty())
    {
        int tmp=q.front();q.pop();
        foreach(it,vc[tmp])
        {
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
        if(vis[it->to]==false&&d[x]+1==d[it->to]&&it->c>0)
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
        int f;
        while(MS(vis,false),f=DFS(source,0x3f3f3f3f))flow+=f;
    }
    return flow;
}
void init()
{
    for(int i=0;i<MAXN*MAXN;i++)vc[i].clear();
}
int main()
{
    int _T;
    scanf("%d",&_T);
    while(_T--)
    {
        init();
        scanf("%d %d %d %d %d%*c",&W,&H,&D,&F,&B);
        for(int i=0;i<H;i++)
        {
            gets(s[i]);
        }
        int ans=0;
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                if((i==0||j==0||i==H-1||j==W-1))
                {
                    if(s[i][j]=='.')ans+=F,s[i][j]='#';
                    addedge(i*W+j,target,0x3f3f3f3f);
                }
            }
        }
        for(int i=1;i<H-1;i++)
        {
            for(int j=1;j<W-1;j++)
            {
                int id=i*W+j;
                if(s[i][j]=='.')addedge(source,id,F);
                else addedge(id,target,D);
                for(int k=0;k<4;k++)
                {
                    int tx=i+dx[k],ty=j+dy[k];
                    if(tx<0||tx>=H||ty<0||ty>=W)continue;
                    addedge(id,tx*W+ty,B);
                }
            }
        }
        printf("%d\n",ans+Dinic());
    }
}
