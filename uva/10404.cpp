#include <stdio.h>
#include <string.h>
bool dp[1000010];
int s[20];
int N,M;
int main()
{
	while(~scanf("%d %d",&N,&M))
	{
		for(int i=0;i<M;i++)
		{
			scanf("%d",&s[i]);
		}
		memset(dp,false,sizeof(dp));
		for(int i=0;i<=N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(i-s[j]>=0&&dp[i-s[j]]==false)
				{
					dp[i]=true;
					break;
				}
			}
		}
		if(dp[N])puts("Stan wins");
		else puts("Ollie wins");
	}
	return 0;
}
