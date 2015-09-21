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
int vis[50010],low[50010];
int tt=0;
int ans=0;
void dfs(int x,int p)
{
	vis[x]=low[x]=++tt;
	foreach(it,vc[x])
	{
		if(*it==p)continue;
		if(vis[*it])
		{
			low[x]=min(low[x],vis[*it]);
		}
		else
		{
			dfs(*it,x);
			low[x]=min(low[x],low[*it]);
			//printf("%d %d %d\n",*it,vis[*it],low[*it]);
			if(low[*it]>=vis[*it])ans++;
		}
	}
}
int main()
{
	MS(vis,0);
	MS(low,0);
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].PB(b);
		vc[b].PB(a);
	}
	for(int i=1;i<=N;i++)
		if(vis[i]==0)dfs(i,i);
	printf("%d\n",ans);
	return 0;
}

