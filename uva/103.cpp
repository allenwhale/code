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
int K,N;
struct box
{
	int deg[11];
	int idx;
	bool operator < (const box& n)const
	{
		for(int i=0;i<N;i++)
		{
			if(n.deg[i]!=deg[i])return n.deg[i]>deg[i];
		}
		return false;
	}
}b[40];
int dp[40];
int back[40];
bool cmp(box a,box aa)
{
	for(int i=0;i<N;i++)
	{
		if(a.deg[i]>=aa.deg[i])return false;
	}
	return true;
}
int main()
{
	while(~scanf("%d %d",&K,&N))
	{
		for(int i=0;i<K;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&b[i].deg[j]);
			}
			b[i].idx=i;
			sort(b[i].deg,b[i].deg+N);
		}
		sort(b,b+K);
		for(int i=0;i<K;i++)dp[i]=1;
		for(int i=1;i<K;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(cmp(b[j],b[i])&&dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					back[i]=j;
				}
			}
		}
		int ans=-1;
		int f;
		for(int i=0;i<K;i++)
		{
			if(ans<dp[i])
			{
				ans=dp[i];
				f=i;
			}
		}
		printf("%d\n",ans);
		deque<int>dq;
		for(int i=f;;i=back[i])
		{
			dq.PF(i);
			if(dp[i]==1)break;
		}
		for(int i=0;i<ans;i++)
		{
			printf("%d%c",b[dq[i]].idx+1,i==ans-1?'\n':' ');
		}
	}
 	return 0;
}

