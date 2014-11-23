#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
char tmp[220][220];
char map[220][220];
int dp[220][220];
int turn(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
	{
		ans+=2*i-1;
	}
	return ans;
}
int main()
{
	int N;
	int num=1;
	while(scanf("%d",&N))
	{
		if(N==0)break;
		//getchar();
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++)
		{
			scanf("%s",tmp[i]);
			//puts(tmp[i]);
		}
		memset(map,' ',sizeof(map));
		for(int i=0;i<N;i++)
		{
			int j;
			for(j=0;j<2*N-(2*i+1);j++)
			{
				//printf("%d %d %c\n",i,j+i,tmp[i][j]);
				map[i][j+i]=tmp[i][j];
			}
			map[i][j+i]='\0';
			//puts(map[i]);
		}
		//for(int i=0;i<N;i++)puts(map[i]);
		int ans=0;
		for(int i=0;i<N;i++)
		{
			for(int j=i;j<2*N-i-1;j++)
			{
				if((i&1)!=(j&1))continue;
				if(map[i][j]=='-')dp[i][j]=1;
				if(map[i][j]=='-'&&map[i-1][j]=='-')dp[i][j]+=min(dp[i-1][j+1],dp[i-1][j-1]);
				//printf("%c %d %d %d\n",map[i][j],i,j,dp[i][j]);
				ans=max(ans,dp[i][j]);
			}
		}
		for(int i=N-1;i>=0;i--)
		{
			for(int j=i;j<2*N-i-1;j++)
			{
				if((i&1)==(j&1))continue;
				if(map[i][j]=='-')dp[i][j]=1;
				if(map[i][j]=='-'&&map[i+1][j]=='-')dp[i][j]+=min(dp[i+1][j+1],dp[i+1][j-1]);
				//printf("%c %d %d %d\n",map[i][j],i,j,dp[i][j]);
				ans=max(ans,dp[i][j]);
			}
		}
		printf("Triangle #%d\nThe largest triangle area is %d.\n\n",num++,turn(ans));
	}
    return 0;
}
