#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
int ispal[1010][1010],dp[1010];
char s[1010];
int n;
int findpal(int x,int y)
{
	int &t=ispal[x][y];
	if(t!=-1)return t;
	if(x>=y)return t=1;
	if(s[x]!=s[y])return t=0;
	return t=findpal(x+1,y-1);
}
int minpart()
{
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1e9;
		for(int j=0;j<i;j++)
		{
			//printf("%d %d %d\n",j+1,i,findpal(j+1,i));
			if(findpal(j+1,i)==1)
			{
				dp[i]=min(dp[i],dp[j]+1);
			}
			//printf("%d %d\n",i,dp[i]);
		}		
	}
	return dp[n];
}
int main()
{
	char a[100];
	gets(a);
	int t;
	sscanf(a,"%d",&t);
	for(int i=0;i<t;i++)
	{
		gets(s+1);
		n=strlen(s+1);
		memset(ispal,-1,sizeof(ispal));
		int ans=minpart();
		printf("%d\n",ans);
	}
    return 0;
}
