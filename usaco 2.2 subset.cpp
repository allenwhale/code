/*
ID: allenwh1
PROG: subset
LANG: C++
*/
#include <stdio.h>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
int N;
long long dp[100][5100];
int main()
{
	fin("subset.in");
	fout("subset.out");
	scanf("%d",&N);
	if(!((N%4==0)||((N+1)%4==0)))
	{
		printf("0\n");
		return 0;
	}
	int half=N*(N+1)/4;
	dp[1][1]=1;
	dp[1][0]=1;
	for(int i=2;i<=N;i++)
	{
		int sum=i*(i+1)/2;
		for(int j=0;j<=sum;j++)
		{
			if(j>=i)dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
			else dp[i][j]=dp[i-1][j];
		}
	}
	printf("%lld\n",dp[N][half]/2);
    return 0;
}
