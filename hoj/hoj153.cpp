#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <complex>
#include <functional>
#include<bits/stdc++.h>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>tmap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>tset;
inline int getint()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	int x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
inline ll getll()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	ll x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
struct E
{
	int to,c;
	E(){}
	E(int _t,int _c)
	{
		to=_t,c=_c;
	}
};
int N,M1,M2;
vector<E>vc[610];
int dfn[610],low[610],t=0,cnt=0;
bool in_stack[610];
int sta[610],*st=sta;
int scc[610];
int dis[610][610];
vector<int>tsort;
void dfs(int x)
{
	dfn[x]=++t;low[x]=dfn[x];
	in_stack[x]=true;
	*st++=x;
	foreach(it,vc[x])
	{
		if(dfn[it->to]==0)
		{
			dfs(it->to);
			low[x]=min(low[x],low[it->to]);
		}
		else if(in_stack[it->to])
		{
			low[x]=min(low[x],dfn[it->to]);
		}
	}
	if(low[x]==dfn[x])
	{
		int c=++cnt;
		int w;
		do
		{
			w=*--st;
			tsort.PB(w);
			scc[w]=c;
			in_stack[w]=false;
			//printf("w %d\n",w);
		}while(w!=x);
	}
}
int main()
{
	N=getint();
	M1=getint();
	M2=getint();
	for(int i=0;i<M1;i++)
	{
		int a,b;
		a=getint();
		b=getint();
		vc[a].PB(E(b,1));
		vc[b].PB(E(a,-1));
	}
	for(int i=0;i<M2;i++)
	{
		int a,b;
		a=getint();
		b=getint();
		vc[a].PB(E(b,0));
	}
	MS(dfn,0);
	//puts("st dfs");
	for(int i=1;i<=N;i++)
		if(dfn[i]==0)
		{
			//printf(" %d\n",i);
			dfs(i);
		}
	//printf("sz %d\n",SIZE(tsort));
	//foreach(it,tsort)
	//{
		//printf(" %d",*it);
	//}
	//puts("");
	//puts("dfs");
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
		{
			dis[i][j]=INT_MIN;
		}
	}
	for(int i=1;i<=N;i++)
	{
		dis[i][i]=0;
		foreach(it,vc[i])
		{
			if(scc[i]==scc[it->to])dis[i][it->to]=max(dis[i][it->to],it->c);
		}
	}
	for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(dis[i][k]!=INT_MIN&&dis[k][j]!=INT_MIN)
				{
					dis[i][j]=max(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}/*
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			printf("%d ",dis[i][j]);
		}
		puts("");
	}*/
	for(int i=1;i<=N;i++)
	{
		if(dis[i][i]>0)
		{
			puts("NIE");
			return 0;
		}
	}
	int ans=0;
	for(int i=0;i<N;)
	{
		//printf("now %d %d %d\n",i,tsort[i],scc[tsort[i]]);
		int j=i;
		while(j<N&&scc[tsort[j]]==scc[tsort[i]])j++;
		int tans=0;
		
		for(int k=i;k<j;k++)
		{
			for(int l=i;l<j;l++)
			{
				tans=max(tans,abs(dis[tsort[k]][tsort[l]]));
			}
		}
		//printf("tans %d\n",tans);
		ans+=tans+1;
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}


