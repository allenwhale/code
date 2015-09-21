#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
char s[1010];
int dp[1010][1010];
int pre[1010][1010];
int n;
int find(int x,int y)
{
	if(dp[x][y]!=-1)return dp[x][y];
	if(x>=y)return dp[x][y]=0;
	if(s[x]==s[y])
	{
		pre[x][y]=0;
		return dp[x][y]=find(x+1,y-1);
	}
	int p=find(x+1,y),l=find(x,y-1);
	if(p<l)
	{
		pre[x][y]=1;
		return dp[x][y]=p+1;
	}
	else
	{
		pre[x][y]=-1;
		return dp[x][y]=l+1;
	}
}
void print(int x,int y)
{
	if(x>y)return;
	if(x==y)
	{
		printf("%c",s[x]);
		return;
	}
	else if(pre[x][y]==0)
	{
		printf("%c",s[x]);
		print(x+1,y-1);
		printf("%c",s[y]);
		return;
	}
	else if(pre[x][y]==1)
	{
		printf("%c",s[x]);
		print(x+1,y);
		printf("%c",s[x]);
		return;
	}
	else
	{
		printf("%c",s[y]);
		print(x,y-1);
		printf("%c",s[y]);
		return;
	}
}
int main()
{
	while(gets(s)!=NULL)
	{
		n=strlen(s);
		memset(dp,-1,sizeof(dp));
		printf("%d ",find(0,n-1));
		print(0,n-1);
		printf("\n");
	}
    return 0;
}
