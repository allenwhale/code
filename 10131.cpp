#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <time.h>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#ifndef _PUSH_POP_
#define _PUSH_POP_
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#endif
#ifndef _MS_
#define _MS_
#define MS(s,v) memset(s,v,sizeof(s))
#endif
#ifndef _PAIR_
#define _PAIR_
#define PI pair<int,int>
#define PD pair<double,double>
#define PL pair<long long,long long>
#define MP(a,b) make_pair(a,b)
#define FF first
#define SS second
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
struct ele
{
	int w,s,idx;
	ele(){}
	ele(int _w,int _s,int _i)
	{
		w=_w,s=_s,idx=_i;
	}
}e[1010];
bool cmp1(ele a,ele b)
{
	return a.w>b.w;
}
int dp[1010];
int ptr[1010];
int main()
{
	int n=1;
	int w,s;
	while(~scanf("%d %d",&w,&s))
	{
		e[n]=ele(w,s,n);
		n++;
	}
	sort(e,e+n,cmp1);
	fill(dp,dp+n+1,1);
	MS(ptr,-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(e[i].w<e[j].w&&e[i].s>e[j].s)
			{
				if(dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					ptr[i]=j;
				}
			}
		}
	}
	int ans=-1,pp;
	for(int i=1;i<=n;i++)
	{
		if(ans<dp[i])
		{
			ans=dp[i];
			pp=i;
		}
	}
	printf("%d\n",ans);
	for(int i=pp;i!=-1;i=ptr[i])
	{
		printf("%d\n",e[i].idx);
	}
 	return 0;
}

