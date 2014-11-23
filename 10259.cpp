#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int mp[110][110];
int dp[110][110];
bool vis[110][110];
int N,K;
bool isin(int x,int y)
{
	return x>=0&&x<N&&y>=0&&y<N;
}
struct sta
{
	pair<int,int> t;
	int c;
	sta(){}
	sta(pair<int,int> _t,int _c)
	{
		t=_t,c=_c;
	}
	bool operator < (const sta& n)const
	{
		return n.c>c;
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&K);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		MS(dp,-1);
		MS(vis,false);
		priority_queue<sta>q;
		dp[0][0]=mp[0][0];
		q.push(sta(make_pair(0,0),dp[0][0]));
		int ans=-1;
		while(!q.empty())
		{
			sta tmp=q.top();
			q.pop();
			int x=tmp.t.first,y=tmp.t.second;
			//if(vis[x][y])continue;
		//	printf(" %d %d %d\n",x,y,dp[x][y]);
			ans=max(ans,dp[x][y]);
			vis[x][y]=true;
			for(int i=1;i<=K;i++)
			{
				if(!isin(x+i,y))break;
				if(mp[x+i][y]>mp[x][y]&&dp[x+i][y]<dp[x][y]+mp[x+i][y])
				{
					dp[x+i][y]=dp[x][y]+mp[x+i][y];
					q.push(sta(make_pair(x+i,y),dp[x+i][y]));
				}
			}
			for(int i=1;i<=K;i++)
			{
				if(!isin(x-i,y))break;
				if(mp[x-i][y]>mp[x][y]&&dp[x-i][y]<dp[x][y]+mp[x-i][y])
				{
					dp[x-i][y]=dp[x][y]+mp[x-i][y];
					q.push(sta(make_pair(x-i,y),dp[x-i][y]));
				}
			}
			for(int i=1;i<=K;i++)
			{
				if(!isin(x,y+i))break;
				if(mp[x][y+i]>mp[x][y]&&dp[x][y+i]<dp[x][y]+mp[x][y+i])
				{
					dp[x][y+i]=dp[x][y]+mp[x][y+i];
					q.push(sta(make_pair(x,y+i),dp[x][y+i]));
				}
			}
			for(int i=1;i<=K;i++)
			{
				if(!isin(x,y-i))break;
				if(mp[x][y-i]>mp[x][y]&&dp[x][y-i]<dp[x][y]+mp[x][y-i])
				{
					dp[x][y-i]=dp[x][y]+mp[x][y-i];
					q.push(sta(make_pair(x,y-i),dp[x][y-i]));
				}
			}
		}
		printf("%d\n",ans);
		if(T)puts("");
	}
	return 0;
}

