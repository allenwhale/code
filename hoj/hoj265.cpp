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
ll W;
struct peo
{
	int s,q,idx;
	double p;
	peo(){}
	peo(int _s,int _q,int _i)
	{
		s=_s,q=_q,idx=_i;
		p=(double)s/(double)q;
	}
	bool operator < (const peo &n)const
	{
		return p<n.p;
	}
}P[500010];
bool h[500010];
int main()
{
	scanf("%d "__lld,&N,&W);
	for(int i=0;i<N;i++)
	{
		int s,q;
		scanf("%d %d",&s,&q);
		P[i]=peo(s,q,i+1);
	}
	sort(P,P+N);
	double mn=1e9;
	int idx=-1;
	priority_queue<int>pq;
	ll totq=0ll;
	int sz=0;
	for(int i=0;i<N;i++)
	{
		//printf("  %lf\n",P[i].p);
		totq+=(ll)P[i].q;
		pq.push(P[i].q);
		double totc=(double)totq*P[i].p;
		//printf("totc %lf\n",totc);
		while(totc>(double)W)
		{
			totq-=pq.top();
			pq.pop();
			totc=(double)totq*P[i].p;
		}
		if(SIZE(pq)>sz||(SIZE(pq)==sz&&totc<mn))
		{
			sz=pq.size();
			mn=totc;
			idx=i;
		}
	}
	priority_queue<pI>pq2;
	for(int i=0;i<=idx;i++)
	{
		pq2.push(MP(P[i].q,P[i].idx));
		h[P[i].idx]=true;
	}
	while(SIZE(pq2)>sz)
	{
		h[pq2.top().SS]=false;
		pq2.pop();
	}
	printf("%d\n",sz);
	for(int i=1;i<=N;i++)
		if(h[i])printf("%d\n",i);
	return 0;
}

