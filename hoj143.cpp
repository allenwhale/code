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
vector<int>vc[50010];
int N,M;
int ap=0;
bool vis[50010];
int low[50010],dfn[50010];
int tt=0;
void dfs(int x,int px)
{
	vis[x]=true;
	dfn[x]=low[x]=++tt;
	int ch=0;
	bool app=false;
	foreach(it,vc[x])
	{
		if(*it==px)continue;
		if(vis[*it])low[x]=min(low[x],dfn[*it]);
		else 
		{
			ch++;
			dfs(*it,x);
			low[x]=min(low[x],low[*it]);
			if(low[*it]>=dfn[x])app=true;
		}
	}
	if((x==1&&ch>1)||(x!=1&&app))ap++;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].PB(b);
		vc[b].PB(a);
	}
	dfs(1,1);
	printf("%d\n",ap);
	return 0;
}

