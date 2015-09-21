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
int N,M;
int p[50010];
struct E
{
	int a,b,w;
	bool operator < (const E &n)const
	{
		return w<n.w;
	}
}e[200010];
void init()
{
	for(int i=0;i<=N;i++)
	{
		p[i]=i;
	}
}
int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b)
{
	p[find(a)]=find(b);
}
int main()
{
	
	scanf("%d %d",&N,&M);
	init();
	for(int i=0;i<M;i++)
		scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].w);
	sort(e,e+M);
	int g=N;
	int ans=0;
	for(int i=0;i<M&&g>1;i++)
	{
		int a,b,w;
		a=e[i].a,b=e[i].b,w=e[i].w;
		if(find(a)==find(b))continue;
		ans+=w;
		U(a,b);
		g--;
	}
	if(g!=1)puts("-1");
	else printf("%d\n",ans);
	return 0;
}

