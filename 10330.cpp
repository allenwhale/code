#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
#define MAXN 110
/*
B->0
D->MAXN*2+5
*/
struct edge
{
	int c,rev,to;
	edge(){}
	edge(int _t,int _c,int _r)
	{
		to=_t,c=_c,rev=_r;
	}
};
int N,M,B,D;
vector<edge>vc[MAXN*2+10];
inline void addedge(int a,int b,int c)
{
	vc[a].push_back(edge(b,c,SIZE(vc[b])));
	vc[b].push_back(edge(a,0,SIZE(vc[a])-1));
}
int d[MAXN*2+10];
bool vis[MAXN*2+10];
inline int BFS()
{
	MS(vis,false);
	queue<int>q;
	d[0]=0;
	vis[0]=true;
	q.push(0);
	while(!q.empty())
	{
		int tmp=q.front();q.pop();
		foreach(it,vc[tmp])
		{
			if(vis[it->to]==false&&it->c>0)
			{
				vis[it->to]=true;
				d[it->to]=d[tmp]+1;
				if(it->to==MAXN*2+5)return d[MAXN*2+5];
				q.push(it->to);
			}
		}
	}
	return MAXN*2+10;
}
int DFS(int x,int f)
{
	if(x==MAXN*2+5)return f;
	if(vis[x])return 0;
	vis[x]=true;
	foreach(it,vc[x])
	{
		if(d[x]+1==d[it->to]&&vis[it->to]==false&&it->c>0)
		{
			int flow=DFS(it->to,min(f,it->c));
			if(flow>0)
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
	while(BFS()<MAXN*2+10)
	{
		int f;
		while(true)
		{
			MS(vis,false);
			f=DFS(0,INF);
			if(f)flow+=f;
			else break;
		}
	}
	return flow;
}
inline void init()
{
	for(int i=0;i<=2*N+5;i++)vc[i].clear();
	vc[MAXN*2+5].clear();	
}
int main()
{
	while(~scanf("%d",&N))
	{
		init();
		for(int i=1;i<=N;i++)
		{
			int idx;
			scanf("%d",&idx);
			addedge(i*2,i*2+1,idx);
		}
		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			addedge(a*2+1,b*2,c);
		}
		
		scanf("%d %d",&B,&D);
		for(int i=0;i<B;i++)
		{
			int idx;
			scanf("%d",&idx);
			addedge(0,idx*2,INF);
		}
		for(int i=0;i<D;i++)
		{
			int idx;
			scanf("%d",&idx);
			addedge(idx*2+1,MAXN*2+5,INF);
		}
		//puts("add");
		int ans=Dinic();
		printf("%d\n",ans);
	}
	return 0;
}

