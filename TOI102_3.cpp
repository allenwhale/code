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
int box[110],dp[110][20010];
int N,M,T;//2,1

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(~scanf("%d %d %d",&N,&M,&T))
	{
		for(int i=1;i<=N;i++)
			scanf("%d",&box[i]);
		MS(dp,0);
		int d1=max(T,M),d2=min(T,M);
		int mx1=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j*d1<=box[i];j++)
			{
				int c2=(box[i]-j*d1)/d2;
				for(int k=0;k<=mx1;k++)
				{
					dp[i][k+j]=max(dp[i][k+j],dp[i-1][k]+c2);
				}
			}
			mx1+=(box[i]/d1);
		}
		int ans;
		if(M==d1)
		{
			for(int i=0;i<=mx1;i++)
			{
				ans=max(ans,min(i/2,dp[N][i]));
			}
		}
		else
		{
			for(int i=0;i<=mx1;i++)
			{
				ans=max(ans,min(i,dp[N][i]/2));
			}
		}
		printf("%d\n",ans);
	}
 	return 0;
}

