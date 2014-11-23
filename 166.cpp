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
int s[]={5,10,20,50,100,200};
int a[10];
int dp1[5010];
int dp[5010];
void init()
{
	MS(dp1,0);
	for(int i=0;i<6;i++)
	{
		for(int j=s[i];j<=2000;j++)
		{
			int tmp=1e9;
			for(int k=1;j>=s[i]*k;k++)
			{
				tmp=min(tmp,dp1[j-s[i]*k]+k);
			}
			dp1[j]=tmp;
		}
	}
}
int main()
{
	init();
	while(true)
	{
		int sum=0;
		for(int i=0;i<6;i++)scanf("%d",&a[i]),sum+=a[i]*s[i];
		if(!sum)break;
		int p1,p2;
		scanf("%d.%d",&p1,&p2);
		MS(dp,0x3f);
		dp[0]=0;
		for(int i=0;i<6;i++)
		{
			for(int j=sum;j>=s[i];j--)
			{
				//int tmp=0x3f3f3f3f+1;
				for(int k=0;k<=a[i]&&j>=k*s[i];k++)
				{
					dp[j]=min(dp[j],dp[j-s[i]*k]+k);
				}
				//dp[j]=tmp;
			}
		}
		int ans=1e9;
		for(int i=p1*100+p2;i<=sum;i++)
		{
			ans=min(ans,dp[i]+dp1[i-p1*100-p2]);
			//printf("%d %d %d\n",i,dp[i],dp1[i-p1*100-p2]);
		}
		printf("%3d\n",ans);
	}
 	return 0;
}

