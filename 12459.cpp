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
ll dp[100][2];
int main()
{
	dp[0][0]=1;
	dp[0][1]=0;
	for(int i=1;i<=80;i++)
	{
		dp[i][0]=dp[i-1][1];
		dp[i][1]=dp[i-1][0]+dp[i-1][1];
	}
	int n;
	while(~scanf("%d",&n)&&n)
	{
		printf(__I64d"\n",dp[n][0]+dp[n][1]);
	}
 	return 0;
}

