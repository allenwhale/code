#include <stdio.h>
#include <string.h>
bool g[110][110];
bool dp[110][110];
void init()
{
	memset(g,false,sizeof(g));
	memset(dp,false,sizeof(dp));
}
void warshall(int n)
{
	int i,j,k;
	memset(dp,false,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)dp[i][j]=g[i][j];
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dp[i][k]&&dp[k][j])dp[i][j]=true;
			}
		}
	}
}
int count(int s,int n)
{
	int i;
	int c=0;
	for(i=1;i<=n;i++)
	{
		if(!dp[s][i])c++;
	}
	return c;
}
void print(int s,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!dp[s][i])printf(" %d",i);
	}
}
int main()
{
	int N;
	while(scanf("%d",&N))
	{
		if(N==0)break;
		init();
		int f,t;
		while(scanf("%d",&f))
		{
			if(f==0)break;
			while(scanf("%d",&t))
			{
				//printf("%d\n",t);
				if(t==0)break;
				g[f][t]=true;
			}
		}
		warshall(N);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int s;
			scanf("%d",&s);
			int c=count(s,N);
			printf("%d",c);
			print(s,N);
			printf("\n");
		}
	}
    return 0;
}
