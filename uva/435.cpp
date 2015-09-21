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
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int s[30];
		int sum=0;
		
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];
		}
		int half=sum/2+(sum&1);
		for(int i=0;i<N;i++)
		{
			//printf("  %d\n",i);
			int dp[1010]={0};
			MS(dp,0);
			dp[0]=1;
			for(int j=0;j<N;j++)
			{
				//printf("  %d\n",j);
				if(i==j)continue;
				for(int k=sum;k>=s[j];k--)
				{
					dp[k]+=dp[k-s[j]];
				}
				//printf("");
			}
			int ans=0;
			for(int j=half-s[i];j<half;j++)
			{
				//printf("  %d %d\n",j,dp[j]);
				ans+=dp[j];
			}
			printf("party %d has power index %d\n",i+1,ans);
		}
		puts("");
	}
	return 0;
}

