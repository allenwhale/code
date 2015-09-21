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
int s[110][110];
int sum[110][110];
int N;
int range(int i,int j,int k)
{
	return sum[k][j]-sum[k][i-1];
}
int main()
{
	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
				scanf("%d",&s[i][j]);
		}
		MS(sum,0);
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				sum[i][j]=sum[i][j-1]+s[j][i];
			}
		}
		int ans=-1e9;
		for(int i=1;i<=N;i++)
		{
			for(int j=i;j<=N;j++)
			{
				int b=1;
				int tsum=0;
				while(b<=N)
				{
					tsum+=range(i,j,b);
					//printf(" %d\n",tsum);
					ans=max(ans,tsum);
					if(tsum<0)tsum=0;
					b++;
				}
			}
		//puts("");
		}
		printf("%d\n",ans);
	}
 	return 0;
}

