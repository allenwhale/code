#include <stdio.h>
#include <string.h>
char s1[40],s2[40];
int dp[40][40];
long long kn[40][40];
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=1;i<=N;i++)
	{
		gets(s1+1);
		gets(s2+1);
		int n1=strlen(s1+1);
		int n2=strlen(s2+1);
		memset(kn,0,sizeof(kn));
		for(int i=0;i<=n1;i++)
		{
			dp[i][0]=0;
			kn[i][0]=1;
		}
		for(int i=0;i<=n2;i++)
		{
			dp[0][i]=0;
			kn[0][i]=1;
		}
		for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=n2;j++)
			{
				if(s1[i]==s2[j])
				{
					dp[i][j]=dp[i-1][j-1]+1;
					kn[i][j]+=kn[i-1][j-1];
				}
				else
				{
					dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
					if(dp[i][j]==dp[i-1][j])
					{
						//dp[i][j]=dp[i-1][j];
//						printf("%d %d %d\n",i-1,j,kn[i-1][j]);
						kn[i][j]+=kn[i-1][j];
					}
					if(dp[i][j]==dp[i][j-1])
					{
						//dp[i][j]=dp[i][j-1];
//						printf("%d %d %d\n",i,j-1,kn[i][j-1]);
						kn[i][j]+=kn[i][j-1];
					}
				}
//				printf(" %d %d %d\n",i,j,kn[i][j]);
			}
		}
//		for(int i=1;i<=n1;i++)
//		{
//			for(int j=1;j<=n2;j++)
//			{
//				printf("%d ",kn[i][j]);
//			}
//			printf("\n");
//		}
		printf("Case #%d: ",i);
		printf("%d %lld\n",n1+n2-dp[n1][n2],kn[n1][n2]);
	}
    return 0;
}
