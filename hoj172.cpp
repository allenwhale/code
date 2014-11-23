#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int N,M;
char mp[1010][1010];
int dis[2][1010][1010];
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
bool isin(int x,int y)
{
	return x>=0&&y>=0&&x<N&&y<M&&mp[x][y]!='X';
}
void BFS(int idx,int x,int y)
{
	queue<pI>q;
	q.push(MP(x,y));
	dis[idx][x][y]=0;
	while(!q.empty())
	{
		pI tmp=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			int tx=tmp.FF+dx[i],ty=tmp.SS+dy[i];
			if(isin(tx,ty)&&dis[idx][tx][ty]==0)
			{
				dis[idx][tx][ty]=dis[idx][tmp.FF][tmp.SS]+1;
				q.push(MP(tx,ty));
			}
		}
	}
}
int main()
{
	scanf("%d %d%*c",&N,&M);
	for(int i=0;i<N;i++)
	{
		gets(mp[i]);
	}
	int ax=0,ay=0,cx=0,cy=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(mp[i][j]=='A')ax=i,ay=j;
			if(mp[i][j]=='C')cx=i,cy=j;
		}
	}
	BFS(0,ax,ay);
	BFS(1,cx,cy);
	int ans=INF;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(mp[i][j]=='B')
			{
				if(dis[0][i][j]!=0&&dis[1][i][j]!=0)
				{
					ans=min(ans,dis[0][i][j]+dis[1][i][j]);
				}
			}
		}
	}
	if(ans==INF)puts("-1");
	else printf("%d\n",ans);
	return 0;
}

