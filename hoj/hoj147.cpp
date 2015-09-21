#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
vector<int>vc[8000*4+10],rvc[8000*4+10];
int N,M;
int col[8000*4+10];
int scc[8000*4+10];
int in[8000*4+10];
bool vis[8000*4+10];
void add(int x,int y)
{
	vc[x].PB(y);
	rvc[y].PB(x);
}
#define P 2*N
vector<int>st;
void dfs1(int x)
{
	vis[x]=true;
	foreach(it,vc[x])
	{
		if(!vis[*it])dfs1(*it);
	}
	st.PB(x);
}
void dfs2(int x,int c)
{
	scc[x]=c;
	vis[x]=true;
	foreach(it,rvc[x])
	{
		if(!vis[*it])dfs2(*it,c);
	}
}
int SCC()
{
	MS(vis,false);
	for(int i=1;i<=2*N;i++)
		if(!vis[i])dfs1(i);
	int c=0;
	MS(vis,false);
	for(int i=SIZE(st)-1;i>=0;i--)
	{
		if(!vis[st[i]])dfs2(st[i],c++);
	}
	return c;
}
int main()
{
	
	
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		int a=i*2,b=i*2-1;
		add(a,b+P);
		add(b,a+P);
		add(a+P,b);
		add(b+P,a);
	}
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		add(a,b+P);
		add(b,a+P);
	}
	int sc=SCC();
	bool tf=true;
	for(int i=1;i<=2*N;i++)
	{
		if(scc[i]==scc[i+P])tf=false;
	}
	if(!tf)
	{
		puts("-1");
	}
	else
	{
		for(int i=1;i<=2*N;i++)
		{
			if(scc[i]>scc[i+P])printf("%d\n",i);
		}
	}
	return 0;
}

