#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
long long dp[1000][1000];
int W,N;
void init()
{
	MS(dp,-1ll);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d%*c",&W,&N);
		for(int i=0;i<W;i++)
		{
			//printf(" %d \n",i);
			char tmp[100];
			gets(tmp);
			char *ptr=strtok(tmp	," ");
			ptr=strtok(NULL," ");
			while(ptr!=NULL)
			{
				int idx;
				sscanf(ptr,"%d",&idx);
				dp[i][idx-1]=0ll;
				ptr=strtok(NULL," ");
			}
		}
		dp[0][0]=1;
		for(int i=0;i<W;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i==0&&j==0)continue;
				if(dp[i][j]==0)continue;
				if(i==0)dp[i][j]=dp[i][j-1];
				else if(j==0)dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i-1][j]+dp[i][j-1];
				//printf("  %d %d %d\n",i,j,dp[i][j]);
			}
			
		}
		printf(__lld"\n",dp[W-1][N-1]);
		if(T)puts("");
	}
	return 0;
}

