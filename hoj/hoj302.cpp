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
int N,F;
ll s[100010],sum[100010],p[100010];
struct obj
{
	int i;
	ll n;
	obj(){}
	obj(int _i,ll _n)
	{
		i=_i,n=_n;
	}
};
bool check(ll x)
{
	deque<obj>dq;
	for(int i=1;i<=N;i++)
	{
		p[i]=(ll)sum[i]-(ll)i*x;
		while(!dq.empty()&&dq.back().n<=p[i])dq.PPB();
		dq.PB(obj(i,p[i]));
	}
	for(int i=0;i<=N;i++)
	{
		while(!dq.empty()&&dq.front().i-i<F)dq.PPF();
		if(!dq.empty()&&dq.front().n>=p[i])return true;
	}
	return false;
}
int main()
{
	scanf("%d %d",&N,&F);
	ll mx=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&s[i]);
		s[i]*=1000;
		sum[i]=sum[i-1]+s[i];
		mx=max(s[i],mx);
	}
	int ans=-1;
	ll l=0,r=mx;
	while(l<=r)
	{
		ll mid=((ll)l+r)>>1ll;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}

