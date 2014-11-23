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
#define LLINF (ll)0x3f3f3f3f3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,ll> pI;
typedef pair<double,double>pD;
vector<pI>vc[50010];
ll dis[50010];
int p[50010];
int N,M;
void BFS()
{
	priority_queue<pI>pq;
	pq.push(MP(1,0));
	MS(dis,0x3f);
	dis[1]=0;
	while(!pq.empty())
	{
		pI tmp=pq.top();
		pq.pop();
		if(tmp.SS!=dis[tmp.FF])continue;
		foreach(it,vc[tmp.FF])
		{
			if(dis[it->FF]>dis[tmp.FF]+(ll)it->SS)
			{
				dis[it->FF]=dis[tmp.FF]+(ll)it->SS;
				pq.push(MP(it->FF,dis[it->FF]));
			}
		}
	}
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(MP(b,c));
		vc[b].PB(MP(a,c));
	}
	BFS();
	ll ans=0ll;
	for(int i=1;i<=N;i++)
	{
		if(dis[i]==LLINF)
		{
			ans=-1;
			break;
		}
		ans+=(ll)p[i]*dis[i];
	}
	if(ans!=-1)printf(__lld"\n",ans);
	else printf("No Answer");
	return 0;
}

