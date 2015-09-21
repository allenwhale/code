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
#define PPF(a) push_front(a)
#define PF() pop_front()
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
vector<int>vc[100010];
int dis[100010],low[100010],ch[100010],t;
ll d[100010];
bool vis[100010];
inline void add(int a,int b)
{
	vc[a].PB(b);
	vc[b].PB(a);
}
int dfs(int x,int f)
{
	vis[x]=true;
	low[x]=dis[x]=++t;
	//bool ap=false;
	//int c=0;
	ch[x]=1;
	int tmp=0;
	d[x]=(ll)N-1;
	foreach(it,vc[x])
	{
		int to=*it;
		if(to==f)continue;
		if(vis[to])
		{
			low[x]=min(low[x],dis[to]);
		}
		else
		{
			//c++;
			ch[x]+=dfs(to,x);
			low[x]=min(low[x],low[to]);
			if(low[to]>=dis[x])
			{
				d[x]+=(ll)ch[to]*(N-ch[to]);
			}
			else tmp+=ch[to];
		}
	}
	tmp+=N-ch[x];
	d[x]+=(ll)tmp*(N-tmp);
	return ch[x];
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		add(a,b);
	}
	MS(vis,false);
	t=0;
	dfs(1,0);
	for(int i=1;i<=N;i++)
	{
		//printf("%d %d\n",i,ch[i]);
		printf(__lld"\n",d[i]);
	}
	return 0;
}

