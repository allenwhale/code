#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
int dp[1010][1010];
char s[1010];
int find(int x,int y)
{
	if(dp[x][y]!=-1)return dp[x][y];
	if(x>y)return dp[x][y]=0;
	if(s[x]==s[y])return dp[x][y]=find(x+1,y-1);
	return dp[x][y]=min(find(x+1,y),min(find(x,y-1),find(x+1,y-1)))+1;
}
int main()
{
	char a[10];
	gets(a);
	int t;
	sscanf(a,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		gets(s);
		int n=strlen(s);
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",i,find(0,n-1));
	}
    return 0;
}
