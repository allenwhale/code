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
	int a,b,w;
	E(){}
	E(int _a,int _b,int _w)
	{
		a=_a,b=_b,w=_w;
	}
}e[500000];
int dis[510];
void BFS()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(dis[e[j].b]>dis[e[j].a]+e[j].w)
			{
				dis[e[j].b]=dis[e[j].a]+e[j].w;
			}
		}
	}
}
bool neg()
{
	int t=dis[N];
	BFS();
	return t>dis[N];
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		e[i]=E(a,b,c);
	}
	MS(dis,0x3f);
	dis[1]=0;
	BFS();
	if(dis[N]==INF||neg())puts("QAQ");
	else printf("%d\n",dis[N]);
	return 0;
}

