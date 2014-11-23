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
vector<int>vc[20010];
int scc[20010];
int vis[20010];
int dfn[20010];
int low[20010];
int t=0;
int sta[20020];
int *st=sta;
void dfs(int x)
{
	vis[x]=1;
	*st++=x;
	low[x]=dfn[x]=++t;
	foreach(it,vc[x])
	{
		if(vis[*it]==1)low[x]=min(low[x],dfn[*it]);
		else  if(vis[*it]==0)
		{
			dfs(*it);
			low[x]=min(low[x],low[*it]);
		}
	}
	if(low[x]==dfn[x])
	{
		int tmp;
		do
		{
			tmp=*--st;
			scc[tmp]=x;
			vis[tmp]=2;
		}while(tmp!=x);
	}
}
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	MS(vis,false);
	for(int i=0;i<M;i++)
	{
		int a,b,s;
		scanf("%d %d %d",&a,&b,&s);
		if(s==0)
		{
			vc[b].PB(a);
			vc[a+N].PB(b+N);
		}
		else
		{
			vc[b].PB(a+N);
			vc[a+N].PB(b);
		}
	}
	for(int i=1;i<=2*N;i++)
		if(vis[i]==0)dfs(i);
	for(int i=1;i<=N;i++)
	{
		int sum=0;
		for(int j=1;j<=N;j++)
		{
			//if(i==j)continue;
			if(i!=j&&(scc[i]==scc[j]||scc[i]==scc[j+N]))
			{
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	//while(1);
	return 0;
}

