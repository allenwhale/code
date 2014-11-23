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
int c[400];
ll dp[800];
int main()
{
	int m;
	for(int i=0,j=1;j<=750;i++,j+=2)
	{
		c[i]=j;
		m=i;
	}
	MS(dp,0);
	dp[0]=1;
	for(int i=0;i<=m;i++)
	{
		for(int j=c[i];j<=750;j++)	
		{
			dp[j]+=dp[j-c[i]];
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf(__I64d"\n",dp[n]);
	}
 	return 0;
}

