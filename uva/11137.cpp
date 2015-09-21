#include <stdio.h>
#include <string.h>
long long dp[10000];
int main()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=21;i++)
	{
		int t=i*i*i;
		for(int j=t;j<10000;j++)
		{
			dp[j]+=dp[j-t];
		}
	}
	int N;
	while(~scanf("%d",&N))
	{
		printf("%lld\n",dp[N]);
	}
	#ifdef __ALLEN
	while(1);
	#endif
	return 0;
}