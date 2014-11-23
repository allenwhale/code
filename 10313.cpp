#include <stdio.h>
#include <string.h>
long long dp[310][310];
int main()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=300;i++)
	{
		for(int j=1;j<=300;j++)
		{
			for(int k=i;k<=300;k++)
			{
				dp[j][k]+=dp[j-1][k-i];
			}
		}
	}
	char s[20];
	while(gets(s)!=NULL)
	{
		int N,a,b;
		int flag=sscanf(s,"%d %d %d",&N,&a,&b);
		//printf("%d %d %d %d\n",flag,N,a,b);
		if(a>300)a=300;
		if(b>300)b=300;
		long long sum=0;
		if(flag==1)
		{
			for(int i=0;i<=300;i++)sum+=dp[i][N];
		}
		else if(flag==2)
		{
			for(int i=0;i<=a;i++)sum+=dp[i][N];
		}
		else if(flag==3)
		{
			for(int i=a;i<=b;i++)sum+=dp[i][N];
		}
		printf("%lld\n",sum);
	}
	return 0;
}