#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
char s1[1000],s2[1000];
int dp[1000][1000];
int n;
int main()
{
	char a[10];
	gets(a);
	int t;
	sscanf(a,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		gets(s1+1);
		n=strlen(s1+1);
		for(int i=n;i>0;i--)
		{
			s2[i]=s1[n-i+1];
		}
		for(int i=0;i<=n;i++)
		{
			dp[0][i]=dp[i][0]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s1[i]==s2[j])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		printf("%d\n",dp[n][n]);
	}
    return 0;
}
