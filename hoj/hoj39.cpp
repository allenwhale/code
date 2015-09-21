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
#define lb(x) ((x)&(-(x)))
int K;
int bit[100010];
void add(int x,int v)
{
	for(int i=x;i<=K;i+=lb(i))
	{
		bit[i]+=v;
	}
}
int sum(int x)
{
	int res=0;
	for(int i=x;i>0;i-=lb(i))
	{
		res+=bit[i];
	}
	return res;
}
struct R
{
	ll x,y;
	int xx;
}r[100010];
bool cmp1(const R a,const R b)
{
	return a.y<b.y;
}
bool cmp2(const R a,const R b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d %*lld",&K);
	for(int i=0;i<K;i++)
		scanf(__lld,&r[i].x);
	for(int i=0;i<K;i++)
		scanf(__lld,&r[i].y);
	sort(r,r+K,cmp2);
	r[0].xx=1;
	for(int i=1;i<K;i++)
	{
		//printf(" %d\n",r[i].x);
		if(r[i].x==r[i-1].x)r[i].xx=r[i-1].xx;
		else r[i].xx=r[i-1].xx+1;
	}
	sort(r,r+K,cmp1);
	ll ans=0;
	for(int i=0;i<K;i++)
	{
		//printf("    %d %d\n",r[i].xx,i-sum(r[i].xx));
		ans+=(ll)i-sum(r[i].xx);
		add(r[i].xx,1);
	}
	printf(__lld"\n",ans);
	return 0;
}

