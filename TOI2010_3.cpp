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
int M,N,P;
int s[60][60][2];
int dp[2][10010];
int main()
{
	while(~scanf("%d %d %d",&M,&N,&P))
	{
		int sum=0;
		for(int i=0;i<N;i++)
		{
			int mn=1e9;
			for(int j=0;j<P;j++)
				scanf("%d %d",&s[i][j][0],&s[i][j][1]),mn=min(mn,s[i][j][0]);
			//printf(" %d\n",mn);
			sum+=mn;
		}
		MS(dp,0);
		int flag=0;
		int ans=-1;
		for(int i=0;i<N;i++,flag^=1)
		{
			for(int j=0;j<=M;j++)dp[flag^1][j]=dp[flag][j];
			for(int j=0;j<P;j++)
			{
				for(int k=s[i][j][0];k<=M;k++)
				{
					dp[flag^1][k]=max(dp[flag^1][k],dp[flag][k-s[i][j][0]]+s[i][j][1]);
					ans=max(ans,dp[flag^1][k]);
				}
			}
			for(int j=0;j<M;j++)ans=max(ans,dp[flag^1][j]);
		}
		
		//printf("s %d\n",sum);
		printf("%d\n",ans);
	}
 	return 0;
}

