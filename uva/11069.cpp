#include <stdio.h>
#include <string.h>
int dp[100];
int f(int n)
{
	if(dp[n]!=0)return dp[n];
	if(n==1)return dp[n]=1;
	else if(n==2)return dp[n]=2;
	else if(n==3)return dp[n]=2;
	else return dp[n]=f(n-2)+f(n-3);
}
int main()
{
	memset(dp,0,sizeof(dp));
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",f(n));
	}
    return 0;
}
