#include <stdio.h>
#include <string.h>
#define MAXN 35
#define MAXS 510
int mp[MAXN*2][MAXN];
long long dp[MAXN*2][MAXN][MAXS];
int N,S;
int main()
{
	while(~scanf("%d %d",&N,&S)&&N)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N-i+1;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		for(int i=N+1;i<2*N;i++)
		{
			for(int j=1;j<=i-N+1;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++)
		{
			dp[2*N-1][i][mp[2*N-1][i]]=1;
		}
		for(int i=2*N-2;i>=N;i--)
		{
			for(int j=1;j<=i-N+1;j++)
			{
				for(int k=mp[i][j];k<=S;k++)
				{
					dp[i][j][k]+=(dp[i+1][j][k-mp[i][j]]+dp[i+1][j+1][k-mp[i][j]]);
					//printf("%d %d %d %lld\n",i,j,k,dp[i][j][k]);
				}
			}
		}
		for(int i=N-1;i>=1;i--)
		{
			for(int j=1;j<=N-i+1;j++)
			{
				for(int k=mp[i][j];k<=S;k++)
				{
					dp[i][j][k]+=(dp[i+1][j-1][k-mp[i][j]]+dp[i+1][j][k-mp[i][j]]);
					//printf("%d %d %d %lld\n",i,j,k,dp[i][j][k]);
				}
			}
		}
		long long sum=0;
		for(int i=1;i<=N;i++)
		{
			sum+=dp[1][i][S];
		}
		printf("%lld\n",sum);
		for(int i=1;i<=N;i++)
		{
			//printf("dp %lld\n",dp[1][i][S]);
			if(dp[1][i][S])
			{
				printf("%d ",i-1);
				int r=i;
				int s=S;
				for(int j=1;j<=N-1;j++)
				{
					s-=mp[j][r];
					//printf(" %d %d %lld %lld\n",r,s,dp[j+1][r-1][s],dp[j+1][r][s]);
					if(dp[j+1][r-1][s])
					{
						putchar('L');
						
						r--;
					}
					else if(dp[j+1][r][s])
					{
						putchar('R');
						//s-=mp[i][r];
					}		
				}
				for(int j=N;j<=2*N-2;j++)
				{
					s-=mp[j][r];
					//printf(" %d %d %lld %lld\n",r,s,dp[j+1][r][s],dp[j+1][r+1][s]);
					if(dp[j+1][r][s])
					{
						putchar('L');
						
					}
					else if(dp[j+1][r+1][s])
					{
						putchar('R');
						//s-=mp[i][r];
						r++;
					}
				}
				break;
			}
			
		}
		puts("");
	}
	return 0;
}