#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#define INF 9999999
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int s[10010][10010];
bool vis[10010][10010];
struct xy
{
	int x,y;
	xy(int tx,int ty)
	{
		x=tx;
		y=ty;
	}
};
int BFS(int i,int j)
{
	queue<xy>Q;
	Q.push(xy(i,j));
	int a=0;
	int k;
	while(!Q.empty()&&a!=-1)
	{
		xy u=Q.front();
		Q.pop();
		if(vis[u.x][u.y])continue;
		vis[u.x][u.y]=true;
		a++;
		for(k=0;k<=3;k++)
		{
			if(s[u.x][u.y]==s[u.x+dx[k]][u.y+dy[k]])
			{
				if(vis[u.x+dx[k]][u.y+dy[k]]) continue;
				Q.push(xy(u.x+dx[k],u.y+dy[k]));
			}
			else if(s[u.x][u.y]>s[u.x+dx[k]][u.y+dy[k]])
			{
				a=-1;				
				break;
			}
		}
	}
	if(a<0)return 0;
	//printf("%d\n",a);
	return a;
}
int main()
{
	//freopen("A_Large.in","r",stdin);
	//freopen("out.out","w",stdout);
	int n,m;
	int i,j;
	while(~scanf("%d %d",&n,&m))
	{
		memset(vis,false,sizeof(vis));
		for(i=0;i<=m+1;i++)
		{
			for(j=0;j<=n+1;j++)
			{
				s[i][j]=INF;
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&s[i][j]);
			}
		}
		int ans=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(vis[i][j])continue;
				ans+=BFS(i,j);
			}
		}
		printf("%d\n",ans);  
	}
    return 0;
}
