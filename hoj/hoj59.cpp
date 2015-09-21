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
	bool operator < (const E &n)const
	{
		return c>n.c;
	}
};
vector<E>vc[5010];
int dis[2][5010];
int N,M;
void BFS(int idx,int st)
{
	priority_queue<E>pq;
	MS(dis[idx],0x3f);
	dis[idx][st]=0;
	pq.push(E(st,0));
	int cnt=0;
	while(!pq.empty())
	{
		cnt++;
		E tmp=pq.top();pq.pop();
		if(dis[idx][tmp.to]<tmp.c)continue;
		//printf("%d %d\n",tmp.to,tmp.c);
		foreach(it,vc[tmp.to])
		{
			if(dis[idx][it->to]>dis[idx][tmp.to]+it->c)
			{
				dis[idx][it->to]=dis[idx][tmp.to]+it->c;
				pq.push(E(it->to,dis[idx][tmp.to]+it->c));
			}
		}
	}
	//printf("%d\n",cnt++);
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	BFS(0,1);
	BFS(1,N);
	int ans=INF;
	for(int i=1;i<=N;i++)
	{
		foreach(it,vc[i])
		{
			//printf("%d %d %d %d %d \n",i,it->to,it->c,dis[0][i],dis[1][it->to]);
			if(dis[0][i]!=INF&&dis[1][it->to]!=INF)
			{
				if(dis[0][i]+dis[1][it->to]+it->c!=dis[0][N])
					ans=min(ans,dis[0][i]+dis[1][it->to]+it->c);
			}
		}
	}
	if(ans!=INF)printf("%d\n",ans);
	else printf("0\n");
	return 0;
}

