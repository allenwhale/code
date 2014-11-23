#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#define PB push_back
#define PPB pop_back
#define MS(s,v) memset(s,v,sizeof(s))
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define PI pair<int,int>
#define FF first
#define SS second
#define MP(x,y) make_pair(x,y)
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int N,M,bnum,xnum;
int dp[1<<17];
char mp[50][50];
int fix[50][50];
int dis[16][16];
int lx[16],ly[16];
int q[100],qf,qb;
int mx[20],my[20];
int py[16];
bool isin(int x,int y)
{
	return (x>=0&&x<N&&y>=0&&y<M)&&mp[x][y]!='#';
}
void BFS(int sx,int sy)
{
	bool vis[50][50];
	int d[50][50];
	int s=fix[sx][sy];
	MS(vis,false);
	MS(d,0);
	queue<PI> q;
	vis[sx][sy]=true;
	d[sx][sy]=0;
	q.push(MP(sx,sy));
	while(!q.empty())
	{
		PI t=q.front();
		q.pop();
		int x=t.FF,y=t.SS;
		//printf(" %d %d %d\n",x,y,fix[x][y]);
		if(fix[x][y]>=100)
		{
			//printf("%d %d %d\n",s,x,y);
			dis[s][fix[x][y]-100]=d[x][y];
		}
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
		//	printf("%d %d %c %d\n",tx,ty,mp[tx][ty],vis[tx][ty]);
			if(isin(tx,ty)&&!vis[tx][ty])
			{
				vis[tx][ty]=true;
				d[tx][ty]=d[x][y]+1;
				q.push(MP(tx,ty));
			}
		}
	}
	return;
}
bool match(int s)
{
	while(true)
	{
		MS(py,-1);
		int lack=1e9;
		for(qf=qb=0,q[qb++]=s;qf<qb;)
		{
			for(int i=q[qf++],j=0;j<xnum;j++)
			{
				if(py[j]!=-1)continue;
				int t=(-lx[i]-ly[j]+dis[i][j]);
				//printf(" t %d\n",t);
				if(t==0)
				{
					py[j]=i;q[qb++]=my[j];
					if(my[j]==-1)
					{
						for(int ty=0;ty!=-1;j=ty)
						{
							ty=mx[i=py[j]],mx[i]=j,my[j]=i;
						}
						return true;
					}
				}
				else
				{
					lack=min(lack,t);
				}
			}
		}
		if(lack==1e9)
		{
			//puts("1e9");
			return false;
		}
		for(int i=0;i<qb;i++)lx[q[i]]+=lack;
		for(int i=0;i<xnum;i++)if(py[i]!=-1)ly[i]-=lack;
	}
	return false;
}
int KM()
{
	MS(lx,0);
	MS(ly,0);
	MS(mx,-1);
	MS(my,-1);
	for(int i=0;i<bnum;i++)
	{
		match(i);
	}
	int res=0;
	for(int i=0;i<bnum;i++)
	{
		//printf(" %d\n",res);
		res+=dis[i][mx[i]];
	}
	return res;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		MS(fix,0);
		MS(dp,-1);
		MS(dis,0x3f);
		MS(mp,0);
		scanf("%d %d%*c",&N,&M);
		xnum=bnum=0;
		for(int i=0;i<N;i++)gets(mp[i]);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			if(mp[i][j]=='B')fix[i][j]=bnum++;
			if(mp[i][j]=='X')fix[i][j]=100+(xnum++);
		}
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			if(mp[i][j]=='B')BFS(i,j);
		}
		printf("%d\n",KM());
	}
	return 0;
}

