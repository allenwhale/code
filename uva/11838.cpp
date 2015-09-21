#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
vector<int>vc[2010],rvc[2010],v,rv;
int N,M;
bool vis[2010];
void dfs(int x)
{
	//printf("  %d\n",x);
	foreach(it,vc[x])
	{
		if(!vis[*it])
		{
			vis[*it]=true;
			dfs(*it);
		}
	}
	v.push_back(x);
}
void rdfs(int x)
{
	//printf("   %d\n",x);
	foreach(it,rvc[x])
	{
		if(!vis[*it])
		{
			vis[*it]=true;
			rdfs(*it);
		}
	}
	rv.push_back(x);
}
bool SCC()
{
	MS(vis,false);v.clear();
	vis[1]=true;
	dfs(1);
	//printf("%d\n",SIZE(v));
	if(SIZE(v)!=N)return false;
	MS(vis,false);rv.clear();
	vis[1]=true;
	rdfs(1);
	//printf("%d\n",SIZE(rv));
	if(SIZE(rv)!=N)return false;
	return true;
}
int main()
{
	while(~scanf("%d %d",&N,&M)&&N&&M)
	{
		for(int i=0;i<=N;i++)
		{
			vc[i].clear();rvc[i].clear();
		}
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			vc[a].push_back(b);
			rvc[b].push_back(a);
			if(c==2)
			{
				vc[b].push_back(a);
				rvc[a].push_back(b);
			}
		}
		if(SCC())puts("1");
		else puts("0");
	}
	return 0;
}

