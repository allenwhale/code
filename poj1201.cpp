#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
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
		return n.c>c;
	}
};
int dis[50010];
int N;
vector<E>vc[50010];
int maxnum;\
int BFS()
{
	queue<int>pq;
	fill(dis,dis+maxnum+1,-INF);
	dis[0]=0;
	pq.push(0);
	while(!pq.empty())
	{
		int tmp=pq.front();pq.pop();
		foreach(it,vc[tmp])
		{
			if(dis[it->to]<dis[tmp]+it->c)
			{
				dis[it->to]=dis[tmp]+it->c;
				pq.push(it->to);
			}
		}
	}
	return dis[maxnum];
}
int main()
{
	scanf("%d",&N);
	maxnum=0;
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(E(b+1,c));
		maxnum=max(maxnum,b+1);
	}
	for(int i=0;i<=maxnum;i++)
	{
		vc[i].PB(E(i+1,0));
		vc[i+1].PB(E(i,-1));
	}
	printf("%d\n",BFS());
	return 0;
}

