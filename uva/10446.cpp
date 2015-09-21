#include <stdio.h>
#include <string.h>
typedef unsigned long long ll;
ll dp[100][100];
int main()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<100;i++)
	{
		dp[0][i]=1;
		dp[1][i]=1;
		dp[i][0]=1;
	}
	for(int i=2;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			for(int k=1;k<=j;k++)
			{
				if(i-k>1)dp[i][j]+=dp[i-k][j];
				else dp[i][j]++;
			}
			dp[i][j]++;
		}
	}
	int n,m;
	int i=0;
	while(~scanf("%d%d",&n,&m))
	{
		i++;
		if(n>60&&m>60)break;
		printf("Case %d: %d\n",i,dp[n][m]);
	}
    return 0;
}
