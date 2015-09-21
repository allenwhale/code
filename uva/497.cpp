#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int b[1000];
int dp[1000];
int pre[1000];
int p[1000];
int len;
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	getchar();
	for(int i=0;i<N;i++)
	{
		if(i)printf("\n");
		
		char s[10];
		len=0;
		memset(b,0,sizeof(b));
		while(gets(s)!=NULL)
		{
			//if(strlen(s)==0)break;
			//puts(s);
			int tmp;
			if(sscanf(s,"%d ",&tmp)!=1)break;
			b[len++]=tmp;
		}
		memset(dp,0,sizeof(dp));
		int ans=0,t;
		for(int i=0;i<len;i++)
		{
			dp[i]=1;
			pre[i]=i;
			for(int j=0;j<i;j++)
			{
				if(b[i]>b[j])
				{
					//dp[i]=max(dp[i],dp[j]+1);
					if(dp[i]<dp[j]+1)
					{
						pre[i]=j;
						dp[i]=dp[j]+1;
					}
				}
			}
			//ans=max(ans,dp[i]);
			//printf("%d %d\n",i,dp[i]);
			if(ans<dp[i])
			{
				ans=dp[i];
				t=i;
			}
			else if(ans==dp[i]&&b[t]>b[i])
			{
				t=i;
			}
		}
		printf("Max hits: %d\n",ans);
		int l=0;
		for(int i=t,j=-1;j!=i;j=i,i=pre[i])
		{
			p[l++]=b[i];
			//printf("%d\n",b[i]);
		}
		if(ans==0)continue;
		for(int i=l-1;i>=0;i--)
		{
			printf("%d\n",p[i]);
		}
	}
	//while(1);
    return 0;
}
