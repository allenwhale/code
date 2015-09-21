#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 110
#define MAXM 40
int N,M;
int P[MAXM];
int dp1[MAXM][MAXN];
int dp2[MAXM][MAXN];
int main()
{
	while(~scanf("%d %d",&N,&M)&&N)
	{
		for(int i=1;i<=M;i++)
		{
			scanf("%d",&P[i]);
		}
		//memset(dp1,0,sizeof(dp1));
		memset(dp2,0x3f,sizeof(dp2));
		dp1[0][0]=0x3f3f3f3f;
		for(int i=1;i<=M;i++)
		{
			dp1[i][0]=0x3f3f3f3f;
			for(int j=1;j<=N;j++)
			{
				dp1[i][j]=dp1[i-1][j];
				for(int k=1;k<=j;k++)
				{
					dp1[i][j]=max(dp1[i][j],min(dp1[i-1][j-k],P[i]/k));
				}
			}
		}
		dp2[0][0]=0;
		for(int i=1;i<=M;i++)
		{
			dp2[i][0]=0;
			for(int j=1;j<=N;j++)
			{
				dp2[i][j]=dp2[i-1][j];
				for(int k=1;k<=j;k++)
				{
					if(P[i]/k>=dp1[M][N])
						dp2[i][j]=min(dp2[i][j],dp2[i-1][j-k]+P[i]);
				}
			}
		}
		printf("%d %d\n",dp1[M][N],dp1[M][N]?dp2[M][N]:0);
	}
	return 0;
}