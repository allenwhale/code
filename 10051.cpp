#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 510
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int dp[MAXN][6];
int c[MAXN][6];
typedef pair<int,int> pi;
pi pre[MAXN][6];
char a[][10]={"front","back","left","right","top","bottom"};
int N;
void print(pi n)
{
	if(n.first==-1)return;
	print(pre[n.first][n.second]);
	printf("%d %s\n",n.first+1,a[n.second^1]);
}
int main()
{
	int tt=1;
	while(~scanf("%d",&N)&&N)
	{
		if(tt!=1)puts("");
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<6;j++)
			{
				scanf("%d",&c[i][j]);
			}
		}
		//printf("%d %d\n",c[0][1],c[1][1^1]);
		memset(dp,0,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		for(int j=0;j<6;j++)dp[0][j]=1;
		int ans=0;
		pi st;
		for(int i=1;i<N;i++)
		{
			for(int j=0;j<6;j++)dp[i][j]=1;
			for(int k=0;k<i;k++)
			{
				for(int j=0;j<6;j++)
				{
					for(int l=0;l<6;l++)
					{
						if(c[i][j^1]==c[k][l])
						{
							if(dp[i][j]<dp[k][l]+1)
							{
								pre[i][j]=make_pair(k,l);
								dp[i][j]=dp[k][l]+1;
								//printf("%d %d %d %d\n",i,k,j,dp[i][j]);
								
							}
						}
						
					}
					if(ans<dp[i][j])
					{
						ans=dp[i][j];
						st=make_pair(i,j);
					}
				}
			}
		}
		printf("Case #%d\n%d\n",tt++,ans);
		print(st);
	}
	return 0;
}
