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
typedef long long ll; 
int N;
ll D[100010],C[100010];
bool check(ll m)
{
	ll CT=0ll;
	for(int i=0;i<N;i++)
	{
		if(C[i]>m)
		{
			CT+=max(0ll,C[i]-m-D[i]);
		}
	}
	for(int i=0;i<N;i++)
	{
		if(C[i]<m)
		{
			CT-=(m-C[i]+D[i]);
		}
	}
	return CT>=0;
}
int main()
{
	scanf("%d",&N);
	ll sum=0ll;
	for(int i=0;i<N;i++)
	{
		scanf(__lld" "__lld,&D[i],&C[i]);
		sum+=C[i];
	}
	ll l=0,r=sum,ans=-(ll)INF*(ll)INF;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=max(ans,mid),l=mid+1;
		else r=mid-1;
	}
	printf(__lld"\n",ans);
	return 0;
}

