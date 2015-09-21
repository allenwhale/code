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
struct E
{
	int a,b;
	double c;
	E(){}
	E(int _a,int _b,double _c)
	{
		a=_a,b=_b,c=_c;
	}
	bool operator < (const E &n)const
	{
		return c>n.c;
	}
}e[100010];
int p[100010];
void init()
{
	for(int i=0;i<=N;i++)
		p[i]=i;
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
	while(~scanf("%d %d",&N,&M))
	{
		init();
		for(int i=0;i<M;i++)
		{
			int a,b;
			double c;
			scanf("%d %d %lf",&a,&b,&c);
			e[i]=E(a,b,c);
		}
		if(N==1)
		{
			puts("No way.");
			continue;
		}
		sort(e,e+M);
		int g=N;
		double ans=1e9;
		for(int i=0;i<M&&g>1;i++)
		{
			if(find(e[i].a)!=find(e[i].b))
			{
				U(e[i].a,e[i].b);
				ans=min(ans,e[i].c);
				g--;
			}
		}
		if(g==1)printf("%.4lf\n",ans);
		else puts("The empire of Arcturus is ending.");
	}
	return 0;
}

