#include <stdio.h>
#include <string.h>
int pre[110];
char s1[110][40],s2[110][40];
struct to
{
	int s1,s2;
}dp[110][110];
int dp2[110][110];
int main()
{
	while(~scanf("%s",s1[1]))
	{
		//printf("%s\n",s1[1]);
		int n1=2;
		while(scanf("%s",s1[n1]))
		{
			//printf(" %s \n",s1[n1]);
			if(s1[n1][0]=='#')break;
			n1++;
		}
		//printf("end1");
		int n2=1;
		while(scanf("%s",s2[n2]))
		{
			//printf(" %s \n",s2[n2]);
			if(s2[n2][0]=='#')break;
			n2++;
		}
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		for(int i=1;i<n1;i++)
		{
			for(int j=1;j<n2;j++)
			{
				if(strcmp(s1[i],s2[j])==0)
				{
					dp2[i][j]=dp2[i-1][i-2]+1;
					dp[i][j].s1=dp[i-1][i-2].s1;
					dp[i][j].s2=dp[i-1][i-2].s2;
				}
				else
				{
					if(dp2[i-1][j]>dp2[i][j-1])
					{
						dp2[i][j]=dp2[i-1][j];
						dp[i][j].s1=dp[i-1][j].s1;
						dp[i][j].s2=dp[i-1][j].s2;
					}
					else
					{
						dp2[i][j]=dp2[i][j-1];
						dp[i][j].s1=dp[i][j-1].s1;
						dp[i][j].s2=dp[i][j-1].s2;
					}
				}
			}
		}
		
		for(int i=dp[n1][n2].s1,j=dp[n1][n2].s2;i!=0&&j!=0;i=dp[i][j].s1,j=dp[i][j].s2)
		{
			printf("%d %d \n",i,j);
			if(strcmp(s1[i],s2[j])==0)
			{
				printf("%s ",s1[i]);
			}
		}
		printf("end");
	}
    return 0;
}
