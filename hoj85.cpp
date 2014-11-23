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
struct W
{
	int x,y;
}w[300010];
bool operator < (const W a,const W b)
{
	return a.x<b.x;
}
bool cmp1(W a,W b)
{
	return a.y>b.y;
}
bool cmp2(W a,W b)
{
	return a.x>b.x;
}
int N;
bool check(int x)
{
	//printf("x=%d\n",x);
	priority_queue<W>pq;
	ll sum=0;
	for(int i=0;i<x;i++)
	{
		sum+=w[i].x;
		pq.push(w[i]);
	}
	if(sum<=(ll)w[x-1].y*x)return true;
	for(int i=x;i<N;i++)
	{
		//printf(" %d\n",pq.top().x);
		if(w[i].x<pq.top().x)
		{
			sum-=pq.top().x;
			pq.pop();
			sum+=(ll)w[i].x;
			pq.push(w[i]);
			if(sum<=(ll)w[i].y*x)return true;
		}
		
	}
	return false;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&w[i].x,&w[i].y);
	}
	sort(w,w+N,cmp1);
	int l=0,r=N;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

