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
struct tur
{
	int w,s;
	bool operator < (const tur& n)const
	{
		return s<n.s;
	}
}t[6000];
int dp[6000];
int main()
{
	int n=0;
	while(~scanf("%d %d",&t[n].w,&t[n].s))n++;
	sort(t,t+n);
	//for(int i=0;i<n;i++)printf("%d %d\n",t[i].w,t[i].s);
	MS(dp,0x3f);
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=n;j>0;j--)
		{
			if(dp[j-1]+t[i].w<=t[i].s)dp[j]=min(dp[j],dp[j-1]+t[i].w);
		}
	}
	int ans;
	for(int i=n;i>0;i--)
	{
		if(dp[i]!=0x3f3f3f3f)
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
 	return 0;
}

