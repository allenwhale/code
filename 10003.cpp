#include <stdio.h>
#define min(a,b) (a>b?b:a)
#define INF 9999999
int c[1010];
int N,num;
int dp[1010][1010];
int cut(int f,int t)
{
	if(dp[f][t]!=-1)return dp[f][t];
	int &tmp=dp[f][t];
	tmp=INF;
	for(int i=0;i<num;i++)
	{
		if(c[i]>f&&c[i]<t)
		{
			tmp=min(tmp,cut(f,c[i])+cut(c[i],t)+(t-f));
		}
	}
	return tmp==INF?tmp=0:tmp;
}
int main()
{
	while(scanf("%d",&N))
	{
		if(N==0)break;
		scanf("%d",&num);
		for(int i=0;i<num;i++)
		{
			scanf("%d",&c[i]);
		}
		for(int i=0;i<=N;i++)
		{
			for(int j=0;j<=N;j++)
			{
				dp[i][j]=-1;
			}
		}
		printf("The minimum cutting is %d.\n",cut(0,N));
	}
    return 0;
}
