/*
ID: allenwh1
PROG: numtri
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define fo freopen
#define max(a,b) a>b?a:b
int dp[1100][1100];
int s[1100][1100];
int r;
int main()
{
	fo("numtri.in","r",stdin);
	fo("numtri.out","w",stdout);
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&s[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
			dp[i][j]+=s[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=r;i++)
	{
		ans=max(ans,dp[r][i]);
	}
	printf("%d\n",ans);
    return 0;
}
