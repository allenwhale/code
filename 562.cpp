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
int N,a[110];
bool dp[50010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sum=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&a[i]),sum+=a[i];
		sort(a,a+N);
		MS(dp,false);
		dp[0]=true;
		for(int i=0;i<N;i++)
		{
			for(int j=sum;j>=a[i];j--)
			{
				if(dp[j-a[i]])dp[j]=true;
			}
		}
		int h=sum/2;
		int ans=-1;
		for(int i=h;i<=sum&&ans==-1;i++)
		{
			if(dp[i]&&dp[sum-i])
			{
				ans=abs(2*i-sum);
			}
		}
		printf("%d\n",ans);
	}
 	return 0;
}

