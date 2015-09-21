#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int s[110];
long long dp[100*450/2+10];
int main()
{
	int T;
	scanf("%d",&T);
	int N;
	while(T--)
	{
		MS(dp,0ll);
		dp[0]=1ll;
		scanf("%d",&N);
		int sum=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];
		}
		for(int i=0;i<N;i++)
		{
			for(int j=sum/2+1;j>=s[i];j--)
			{
				dp[j]|=dp[j-s[i]]<<1ll;
			}
		}
		int hs=sum/2,hn=N/2;
		if(N&1)
		{
			while(!(dp[hs]&(1ll<<hn))&&!(dp[hs]&(1ll<<(hn+1))))hs--;
		}
		else
		{
			while(!(dp[hs]&(1ll<<hn))&&!(dp[sum-hs]&(1ll<<hn)))hs--;
		}
		printf("%d %d\n",hs,sum-hs);
		if(T)puts("");
	}
	return 0;
}

