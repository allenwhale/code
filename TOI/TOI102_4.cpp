#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <time.h>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#ifndef _PUSH_POP_
#define _PUSH_POP_
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#endif
#ifndef _MS_
#define _MS_
#define MS(s,v) memset(s,v,sizeof(s))
#endif
#ifndef _PAIR_
#define _PAIR_
#define PI pair<int,int>
#define PD pair<double,double>
#define PL pair<long long,long long>
#define MP(a,b) make_pair(a,b)
#define FF first
#define SS second
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
vector<int>vc[100010];
vector<int >vc1[100010];
vector<int>pos;
bool vis[100010];
int N,M;
int p[100010];
int g[100010];
int scc=0;
inline void init()
{
	//for(int i=0;i<=N;i++)p[i]=i;
	MS(p,-1);
}
inline int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
inline void U(int a,int b)
{
	p[max(a,b)]=find(p[min(a,b)]);
}
void dfs(int x)
{
	vis[x]=true;
	int sz=vc1[x].size();
	for(int i=0;i<sz;i++)
	{
		int v=vc1[x][i];
		if(!vis[v])dfs(v);
	}
	pos.PB(x);
}
void rdfs(int x,int pp)
{
	vis[x]=true;
	//U(x,pp);
	p[x]=pp;
	int sz=vc[x].size();
	for(int i=0;i<sz;i++)
	{
		int v=vc[x][i];
		if(!vis[v])rdfs(v,pp);
	}
}
int main()
{
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d %d",&N,&M);
	init();
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].PB(b);
		vc1[b].PB(a);
	}
	MS(vis,false);
	for(int i=1;i<=N;i++)
	{
		if(!vis[i])dfs(i);
	}
	MS(vis,false);
	for(int i=N-1;i>0;i--)
	{
		if(!vis[pos[i]])rdfs(pos[i],scc++);
	}
	for(int i=1;i<=N;i++)
	{
		//printf("  %d %d\n",i,p[i]);
	}
	MS(g,0);
	for(int i=1;i<=N;i++)
	{
		//printf(" %d %d\n",i,find(i));
		g[p[i]]++;
	}
	int cap,mx=-1;
	for(int i=1;i<=N;i++)
	{
		//printf(" %d %d\n",p[i],g[p[i]]);
		if(mx<g[p[i]])
		{
			mx=g[p[i]];
			cap=i;
		}
	}
	MS(vis,false);
	queue<int>q;
	vis[cap]=true;
	q.push(cap);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		int sz=vc[t].size();
		for(int i=0;i<sz;i++)
		{
			int v=vc[t][i];
			if(!vis[v])q.push(v),vis[v]=true;
		}
	}
	int add=0;
	for(int i=1;i<=N;i++)
	{
		if(!vis[i]&&vc1[i].size()==0)
		{
			queue<int>q1;
			vis[i]=true;
			q1.push(i);
			while(!q1.empty())
			{
				int t=q1.front();
				q1.pop();
				int sz=vc1[t].size();
				for(int j=0;j<sz;j++)
				{
					int v=vc1[j].size();
					if(!vis[j])q1.push(v),vis[v]=true;
				}
			}
			add++;
		}
	}
	printf("%d %d\n",cap,add);
 	return 0;
}

