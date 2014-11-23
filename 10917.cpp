#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
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
struct edge
{
	int to,w;
	edge(int _t=0,int _w=0)
	{
		to=_t,w=_w;
	}
};
struct STA
{
	int to,w;
	STA(int _t=0,int _w=0)
	{
		to=_t,w=_w;
	}
	bool operator < (const STA& n)const
	{
		return n.w<w;
	}
};
vector<edge>vc[1010],vc2[1010];
int d[1010],N,M,dp[1010];
bool vis[1010];
void addedge(int a,int b,int c)
{
	vc[a].push_back(edge(b,c));
	vc[b].push_back(edge(a,c));
}
void BFS()
{
	MS(d,0x3f);MS(vis,false);
	d[1]=0;
	priority_queue<STA>pq;
	pq.push(STA(1,0));
	while(!pq.empty())
	{
		STA tmp=pq.top();pq.pop();
		if(vis[tmp.to])continue;
		vis[tmp.to]=true;
		foreach(it,vc[tmp.to])
		{
			if(vis[it->to]==false&&d[it->to]>d[tmp.to]+it->w)
			{
				d[it->to]=d[tmp.to]+it->w;
				pq.push(STA(it->to,d[it->to]));
			}
		}
	}
}
int dfs(int x)
{
	if(dp[x]!=-1)return dp[x];
	if(x==1)return dp[x]=1;
	dp[x]=0;
	foreach(it,vc2[x])
	{
		dp[x]+=dfs(it->to);
	}
	return dp[x];
}
void init()
{
	for(int i=0;i<1010;i++)vc[i].clear(),vc2[i].clear();
}
int main()
{
	while(~scanf("%d",&N)&&N&&~scanf("%d",&M))
	{
		init();
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			addedge(a-1,b-1,c);
		}
		BFS();
		for(int i=0;i<N;i++)
		{
			foreach(it,vc[i])
			{
				if(d[i]>d[it->to])vc2[i].push_back(edge(it->to,0));
			}
		}
		MS(dp,-1);
		printf("%d\n",dfs(0));
	}
	return 0;
}

