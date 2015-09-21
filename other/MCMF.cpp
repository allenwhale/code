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
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#define PB push_back
#define PPB pop_back
#define MS(s,v) memset(s,v,sizeof(s))
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
struct Edge
{
	int to,f,c,rev;
	Edge(){}
	Edge(int _t,int _f,int _c,int _r)
	{
		to=_t,f=_f,c=_c,rev=_r;
	}
};
vector<Edge>vc[1010];
int d[1010];
int p[1010],pr[1010];
int q[10010],qf,qb;
int ansf,ansc;
int N,M;
void addedge(int a,int b,int f,int c)
{
	vc[a].PB(Edge(b,f,c,vc[b].size()));
	vc[b].PB(Edge(a,0,-c,vc[a].size()-1));
	vc[b].PB(Edge(a,f,c,vc[a].size()));
	vc[a].PB(Edge(b,0,-c,vc[b].size()-1));
}
bool BFS(int s,int t)
{
	MS(p,-1);
	MS(d,0x7f);
	qf=qb=0;
	q[qb++]=s;
	d[s]=0;
	while(qf<qb)
	{
		int to=q[qf++];
		int sz=vc[to].size();
		for(int i=0;i<sz;i++)
		{
			Edge e=vc[to][i];
			if(e.f>0)
			{
				if(d[e.to]>d[to]+e.c)
				{
					d[e.to]=d[to]+e.c;
					p[e.to]=to;
					pr[e.to]=i;
					q[qb++]=e.to;
				}
			}
		}
	}
	return d[t]!=0x7f7f7f7f;
}
void MCMF(int s,int t)
{
	ansf=ansc=0;
	while(true)
	{
		if(!BFS(s,t))break;
		int df=1e9;
		for(int i=t,j=p[t];j!=-1;j=p[i=j])
		{
			df=min(df,vc[j][pr[i]].f);
		}
		//printf(" df %d\n",df);
		ansf+=df;
		int dc=0;
		for(int i=t,j=p[t];j!=-1;j=p[i=j])
		{
			vc[j][pr[i]].f-=df;
			vc[i][vc[j][pr[i]].rev].f+=df;
			dc+=(df*vc[j][pr[i]].c);
		}
		//printf("dc %d\n",dc);
		ansc+=dc;
	}
}
int main()
{
	while(~scanf("%d %d",&N,&M))
	{
		for(int i=0;i<M;i++)
		{
			int a,b,f,c;
			scanf("%d %d %d %d",&a,&b,&f,&c);
			addedge(a,b,f,c);
		}
		MCMF(0,N-1);
		printf("flow %d cost %d\n",ansf,ansc);
	}
	return 0;
}

