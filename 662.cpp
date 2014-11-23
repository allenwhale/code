#include <stdio.h>
#include <string.h>
#define MAXN 210
#define MAXP 40
#define abs(a) ((a)<0?-(a):(a))
#define max(a,b) ((a)>(b)?(a):(b))
int dp[MAXP][MAXN];
int pos[MAXP][MAXN];
int dis[MAXN][MAXN];
int N,P;
int s[MAXN];
void print(int p,int n)
{
	if(p==0)return;
	int t=pos[p][n];
	print(p-1,t-1);
	if(t==n)
		printf("Depot %d at restaurant %d serves restaurant %d\n",p,t,t);
	else 
		printf("Depot %d at restaurant %d serves restaurants %d to %d\n",p,(n+t)>>1,t,n);
}
int main()
{
	int tt=1;
	while(~scanf("%d %d",&N,&P)&&N)
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&s[i]);
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=i;j<=N;j++)
			{
				int m=(i+j)>>1;
				dis[i][j]=0;
				for(int k=i;k<=j;k++)
				{
					dis[i][j]+=abs(s[k]-s[m]);
				}
				//printf(" %d %d %d\n",i,j,dis[i][j]);
			}
		}
		memset(dp,0x3f,sizeof(dp));
		memset(pos,0,sizeof(pos));
		dp[0][0]=0;
		for(int i=1;i<=P;i++)
		{
			for(int j=1;j<=N;j++)
			{
				int t=max(pos[i-1][j],pos[i][j-1]);
				for(int k=max(1,t);k<=j;k++)
				{
					if(dp[i][j]>dp[i-1][k-1]+dis[k][j])
					{
						dp[i][j]=dp[i-1][k-1]+dis[k][j];
						pos[i][j]=k;
						//printf("%d %d %d %d %d %d\n",i,j,k,dp[i-1][k-1],dis[k][j],dp[i][j]);
					}
				}
			}
		}
		printf("Chain %d\n",tt++);
		print(P,N);
		printf("Total distance sum = %d\n\n",dp[P][N]);
		
	}
	return 0;
}