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
int N;
struct E
{
	int to,w;
	E(){}
	E(int _t,int _w)
	{
		to=_t,w=_w;
	}
};
vector<E>vc[100010];
int d=0;
int vis[100010];
int dfs(int x,int px)
{
	vis[x]=true;
	int h1=0,h2=0;
	foreach(it,vc[x])
	{
		if(!vis[it->to])
		{
			int h=dfs(it->to,x)+it->w;
			if(h>h1)h2=h1,h1=h;
			else if(h>h2)h2=h;
		}
	}
	d=max(d,h1+h2);
	return h1;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	MS(vis,false);
	dfs(1,1);
	printf("%.1lf\n",(double)d/2);
	return 0;
}

