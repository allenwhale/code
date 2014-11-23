#include <stdio.h>
#include <string.h>
int N,T,sum;
int s[30];
bool dp[10000];
int pre[10000];
int main()
{
	while(~scanf("%d %d",&N,&T))
	{
		memset(dp,0,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		dp[0]=true;
		sum=0;
		for(int i=0;i<T;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];
		}
		for(int i=0;i<T;i++)
		{
			for(int j=N;j>=s[i];j--)
			{
				if(!dp[j])
				{
					if(dp[j-s[i]])
					{
						dp[j]=true;
						pre[j]=j-s[i];
					}
				}
			}
		}
		int ans;
		for(int i=N;i>=0;i--)
		{
			if(dp[i])
			{
				ans=i;
				break;
			}
		}
		int tmp=ans;
		for(int i=pre[tmp];tmp;i=pre[i])
		{
			printf("%d ",tmp-i);
			tmp=i;
		}
		printf("sum:%d\n",ans);
	}
    return 0;
}
