#include <stdio.h>
#include <string.h>


char Ans[110][40];
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
		int n1=2;
		while(scanf("%s",s1[n1]))
		{
			if(s1[n1][0]=='#')break;
			n1++;
		}
		int n2=1;
		while(scanf("%s",s2[n2]))
		{
			if(s2[n2][0]=='#')break;
			n2++;
		}
		//printf("%d %d\n",n1,n2);
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		for(int i=1;i<n1;i++)
		{
			for(int j=1;j<n2;j++)
			{
				if(strcmp(s1[i],s2[j])==0)
				{
					dp2[i][j]=dp2[i-1][j-1]+1;
					dp[i][j].s1=i-1;
					dp[i][j].s2=j-1;
				}
				else
				{
					if(dp2[i-1][j]>dp2[i][j-1])
					{
						dp2[i][j]=dp2[i-1][j];
						dp[i][j].s1=i-1;
						dp[i][j].s2=j;
					}
					else
					{
                        dp2[i][j]=dp2[i][j-1];
						dp[i][j].s1=i;
						dp[i][j].s2=j-1;
					}
				}
			}
		}
		int t1,t2;
		int ans=dp2[n1-1][n2-1];
		//printf("%d\n",ans);
		for(int i=n1-1,j=n2-1;dp2[i][j]!=0;t1=i,t2=j,i=dp[t1][t2].s1,j=dp[t1][t2].s2)
		{
			if(strcmp(s1[i],s2[j])==0)
			{
				strcpy(Ans[ans--],s1[i]);
				//printf("%s ",s1[i]);
			}
		}
		//printf("\n");
		for(int i=1;i<=dp2[n1-1][n2-1];i++)
		{
			printf("%s%c",Ans[i],(i==dp2[n1-1][n2-1])?'\n':' ');
		}
	}
}
