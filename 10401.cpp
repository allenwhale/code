#include <stdio.h>
#include <string.h>
typedef long long ll;
ll dp[25][25];
char s[25];
int use[25];
int main()
{
	while(~scanf("%s",s))
	{
		int len=strlen(s);
		//if(len==0)continue;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;i++)
		{
//			printf(" %c\n",s[i]);
			if(s[i]=='?')use[i+1]=0;
			else if(s[i]>='1'&&s[i]<='9')
			{
				use[i+1]=s[i]-'0';
			}
			else if(s[i]>='A'&&s[i]<='F')
			{
				use[i+1]=s[i]-'A'+10;
			}
//			printf("%d\n",use[i+1]);
		}
//		for(int i=1;i<=len;i++)
//		{
//			printf(" %d",use[i]);
//		}
//		printf("%d\n",use[1]);
		if(use[1])
		{
			dp[1][use[1]]=1;
		}
		else
		{
			for(int i=1;i<=len;i++)
			{
				dp[1][i]=1;
			}
		}
		for(int i=2;i<=len;i++)
		{
			if(use[i])
			{
				for(int j=1;j<=len;j++)
				{
					if(j>=use[i]-1&&j<=use[i]+1)continue;
					dp[i][use[i]]+=dp[i-1][j];
				}
			}
			else
			{
				for(int j=1;j<=len;j++)
				{
					for(int k=1;k<=len;k++)
					{
						if(k>=j-1&&k<=j+1)continue;
						dp[i][j]+=dp[i-1][k];
					}
				}
			}
		}
//		for(int i=1;i<=len;i++)
//		{
//			for(int j=1;j<=len;j++)
//			{
//				printf("%d ",dp[i][j]);
//			}
//			printf("\n");
//		}
		ll ans=0;
		for(int i=1;i<=len;i++)
		{
			ans+=dp[len][i];
		}
		printf("%lld\n",ans);
	}
    return 0;
}
