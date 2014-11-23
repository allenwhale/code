#include <stdio.h>
#define max(a,b) (a>b?a:b)
int dp[110][110];
int s1[110],s2[110];
int main()
{
	int n,m;
	int num=1;
	while(scanf("%d %d",&n,&m))
	{
		if(m==0&&n==0)break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s1[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&s2[i]);
		}
		for(int i=0,j=0;j<=m,i<=n;j++,i++)
		{
			dp[i][0]=dp[0][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}

		printf("Twin Towers #%d\n",num++);
		printf("Number of Tiles : %d\n\n",dp[n][m]);
	}
    return 0;
}
