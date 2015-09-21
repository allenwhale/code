#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX 110
int N,R,C;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool isin(int x,int y)
{
	return x>=0&&y>=0&&x<R&&y<C;
}
int dfs(int x,int y)
{
	//printf(" %d %d\n",x,y);
	int &tmp=dp[x][y];
	if(tmp!=-1)return tmp;
	tmp=1;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(isin(tx,ty)&&map[x][y]>map[tx][ty])
			tmp=max(tmp,dfs(tx,ty)+1);
	}
	return tmp;
}
int main()
{
	scanf("%d",&N);
	while(N--)
	{
		char name[100];
		scanf("%s %d %d",name,&R,&C);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		int ans=-1;
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				//printf("%d %d\n",i,j);
				ans=max(ans,dfs(i,j));
			}
		}
		printf("%s: %d\n",name,ans);
	}
	return 0;
}
