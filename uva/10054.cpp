#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
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
	int to,n;
	edge(int _t=0,int _n=0)
	{
		to=_t,n=_n;
	}
};
vector<edge>vc[60000];
vector<int>E;
int deg[60];
bool vis[1010];
void init()
{
	for(int i=0;i<6000;i++)vc[i].clear();
	E.clear();
	MS(vis,false);
	MS(deg,0);
}
void add(int a,int b,int c)
{
	vc[a].push_back(edge(b,c));
	vc[b].push_back(edge(a,c));
	deg[a]++,deg[b]++;
}
void dfs(int x)
{
	foreach(it,vc[x])
	{
		if(vis[it->n])continue;
		vis[it->n]=true;
		dfs(it->to);
	}
	E.push_back(x);
}
bool check()
{
	for(int i=0;i<=50;i++)
	{
		if(deg[i]&&(deg[i]&1))return false;
	}
	return true;
}
int main()
{
	int T;
	int t=1;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		init();
		int a,b;
		for(int i=0;i<N;i++)
		{			
			scanf("%d %d",&a,&b);
			add(a,b,i);
		}
		printf("Case #%d\n",t++);
		if(check())dfs(a);
		else 
		{
			puts("some beads may be lost");
			if(T)puts(""); 
			continue;
		}
		//printf("%d\n",);
		if(SIZE(E)!=N+1)puts("some beads may be lost");
		else
		{
			for(int i=0;i<N;i++)
			{
				printf("%d %d\n",E[i],E[i+1]);
			}
		}
		if(T)puts(""); 
	}
	return 0;
}

