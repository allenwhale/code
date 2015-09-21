#include <stdio.h>
#define max(a,b) (a>b?a:b)
int s[100];
int dp[100];
int main()
{
	int num=0;
	while(1)
	{
		
		int len=0;
		int tmp;
		scanf("%d",&tmp);
		if(tmp==-1)break;
		s[len++]=tmp;
		if(num)printf("\n");
		while(scanf("%d",&tmp))
		{
			if(tmp==-1)break;
			s[len++]=tmp;
		}
		int ans=0;
		for(int i=0;i<len;i++)
		{
			dp[i]=1;
			for(int j=0;j<i;j++)
			{
				if(s[i]>=s[j])continue;
				dp[i]=max(dp[i],dp[j]+1);
			}
			ans=max(ans,dp[i]);
		}
		printf("Test #%d:\n",++num);
		printf("  maximum possible interceptions: %d\n",ans);
	}
    return 0;
}
