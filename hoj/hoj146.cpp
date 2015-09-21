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
struct E
{
	int to,c;
	E(){}
	E(int _t,int _c)
	{
		to=_t,c=_c;
	}
};
vector<E>vc[100010];
int tin[100010],tout[100010],t=0;
bool vis[100010];
int ac[100010][20];
int dis[100010];
void dfs(int x,int px,int d)
{
	dis[x]=d;
	tin[x]=t++;
	vis[x]=true;
	ac[x][0]=px;
	for(int i=1;i<20;i++)
	{
		ac[x][i]=ac[ac[x][i-1]][i-1];
	}
	foreach(it,vc[x])
	{
		if(vis[it->to]==false)
		{
			dfs(it->to,x,d+it->c);
		}
	}
	tout[x]=t++;
}
bool isac(int x,int y)
{
	return tin[x]<=tin[y]&&tout[x]>=tout[y];
}
int LCA(int x,int y)
{
	if(isac(x,y))return x;
	if(isac(y,x))return y;
	for(int i=19;i>=0;i--)
	{
		//printf(" %d\n",x);
		if(!isac(ac[x][i],y))
		{
			x=ac[x][i];
		}
	}
	return ac[x][0];
}
int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	dfs(1,1,0);
	while(Q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		//printf("lca %d\n",LCA(x,y));
		printf("%d\n",dis[x]+dis[y]-2*dis[LCA(x,y)]);
	}
	return 0;
}

