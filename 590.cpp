#include <stdio.h>
#include <string.h>
#define MAXN 15
#define MAXK 1010
int d[MAXN][MAXN];
int p[MAXN][MAXN][40];
int dp[MAXK][MAXN];
int N,K;
int main()
{
	int tt=1;
	while(~scanf("%d %d",&N,&K)&&N)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(i==j)continue;
				scanf("%d",&d[i][j]);
				for(int k=0;k<d[i][j];k++)
				{
					scanf("%d",&p[i][j][k]);
					if(p[i][j][k]==0)p[i][j][k]=0x3f3f3f3f;
				}
			}
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0][1]=0;
		for(int i=1;i<=K;i++)
		{
			for(int j=1;j<=N;j++)
			{	
				for(int k=1;k<=N;k++)
				{
					if(j==k)continue;
					//printf("%d %d\n",j,k);
					int dd=(i-1)%d[k][j];
					
					if(dp[i][j]>dp[i-1][k]+p[k][j][dd])
					{
						dp[i][j]=dp[i-1][k]+p[k][j][dd];
					}
					//printf("%d %d %d\n",i,j,dp[i][j]);
				}
			}
		}
		printf("Scenario #%d\n",tt++);
		if(dp[K][N]>=0x3f3f3f3f)puts("No flight possible");
		else printf("The best flight costs %d.\n",dp[K][N]);
		puts("");
	}
	return 0;
}
