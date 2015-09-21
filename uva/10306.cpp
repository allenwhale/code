#include <stdio.h>
#include <string.h>
#define MAXS 310
#define MAXN 50
#define min(a,b) ((a)<(b)?(a):(b))
int M,S;
int dp[MAXS][MAXS];
int w[MAXN][2];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&M,&S);
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=0;i<M;i++)
		{
			scanf("%d %d",&w[i][0],&w[i][1]);
			for(int x=w[i][0];x<=S;x++)
			{
				for(int y=w[i][1];y<=S;y++)
				{
					if(dp[x][y]>dp[x-w[i][0]][y-w[i][1]]+1)
					{
						dp[x][y]=dp[x-w[i][0]][y-w[i][1]]+1;
					}
				}
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=S;i++)
		{
			for(int j=0;j<=S;j++)
			{
				if(i*i+j*j==S*S)
				{
					ans=min(ans,dp[i][j]);
				}
			}
		}
		if(ans==0x3f3f3f3f)puts("not possible");
		else printf("%d\n",ans);
	}
	return 0;
}