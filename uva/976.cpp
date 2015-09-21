#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int N,M,B,S;
char mp[1010][1010];
bool vis[1010][1010];
int dp[1010][110];
int mindp[110];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int south[1010],north[1010];
inline bool isin(int x,int y)
{
	return x>=0&&x<N&&y>=0&&y<M;
}
void BFS(int x,int y,bool flag)
{
	queue<pair<int,int> >q;
	vis[x][y]=true;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		pair<int,int> tmp=q.front();q.pop();
		if(flag)
		{
			south[tmp.second]=min(south[tmp.second],tmp.first);
		}
		else 
		{
			north[tmp.second]=max(north[tmp.second],tmp.first);
		}
		for(int i=0;i<4;i++)
		{
			int tx=tmp.first+dx[i],ty=tmp.second+dy[i];
			if(isin(tx,ty)&&vis[tx][ty]==false&&mp[tx][ty]=='#')
			{
				vis[tx][ty]=true;
				q.push(make_pair(tx,ty));
			}
		}
	}
}
int main()
{
	while(~scanf("%d %d %d %d%*c",&N,&M,&B,&S))
	{
		for(int i=0;i<N;i++)
			gets(mp[i]);
		MS(south,0x3f);
		MS(north,0xff);
		MS(vis,false);
		BFS(0,0,0);
		BFS(N-1,0,1);
		MS(mindp,0x3f);
		mindp[0]=0;
		for(int i=0;i<M;i++)
		{
			if(i>S)
			{
				for(int j=1;j<=B;j++)
				{
					mindp[j]=min(mindp[j],dp[i-1-S][j]);
				}
			}
			int cost=south[i]-north[i]-1;
			//printf("%d %d %d %d\n",i,cost,south[i],north[i]);
			for(int j=1;j<=B;j++)
			{
				dp[i][j]=cost+mindp[j-1];
			}
		}
		int ans=INF;
		for(int i=0;i<M;i++)
		{
			ans=min(ans,dp[i][B]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

