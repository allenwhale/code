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
#include <time.h>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#ifndef _PUSH_POP_
#define _PUSH_POP_
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#endif
#ifndef _MS_
#define _MS_
#define MS(s,v) memset(s,v,sizeof(s))
#endif
#ifndef _PAIR_
#define _PAIR_
#define PI pair<int,int>
#define PD pair<double,double>
#define PL pair<long long,long long>
#define MP(a,b) make_pair(a,b)
#define FF first
#define SS second
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
PI q[10010];
int qf,qb;
int mp[110][110];
bool vis[110][110];
int N;
bool isin(int x,int y)
{
	return x>0&&x<=100&&y>0&&y<=100;
}
void BFS1(int sx,int sy)
{
	vis[sx][sy]=true;
	qf=qb=0;
	q[qb++]=MP(sx,sy);
	bool tf=false;
	while(qb>qf)
	{
		PI t=q[qf++];
		if(t.FF==1||t.FF==100||t.SS==1||t.SS==100)tf=true;
		for(int i=0;i<4;i++)
		{
			int tx=t.FF+dx[i],ty=t.SS+dy[i];
			if(!isin(tx,ty)||vis[tx][ty]||mp[tx][ty]==1)continue;
			vis[tx][ty]=true;
			q[qb++]=MP(tx,ty);
		}
	}
	if(!tf)
	{
		for(int i=0;i<qb;i++)
		{
			mp[q[i].FF][q[i].SS]=1;
		}
	}
	return;
}
int BFS2(int sx,int sy)
{
	qf=qb=0;
	MS(vis,false);
	q[qb++]=MP(sx,sy);
	vis[sx][sy]=true;
	int cnt=0;
	while(qb>qf)
	{
		PI t=q[qf++];
		for(int i=0;i<4;i++)
		{
			int tx=t.FF+dx[i],ty=t.SS+dy[i];
			if(!isin(tx,ty))cnt++;
			else if(mp[tx][ty]==0)cnt++;
		}
		for(int i=0;i<4;i++)
		{
			int tx=t.FF+dx[i],ty=t.SS+dy[i];
			if(isin(tx,ty)&&mp[tx][ty]==1&&!vis[tx][ty])
			{
				vis[tx][ty]=true;
				q[qb++]=MP(tx,ty);
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	scanf("%d",&N);
	MS(mp,0);
	MS(vis,false);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		mp[a][b]=1;
	}
	/*
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%d",mp[i][j]);
		}
		puts("");
	}
	puts("");
	*/
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(vis[i][j]==false&&mp[i][j]==0)
			{
				//printf(" %d %d\n",i,j);
				BFS1(i,j);
				/*for(int ii=1;ii<=10;ii++)
				{
					for(int jj=1;jj<=10;jj++)
					{
						printf("%d",mp[ii][jj]);
					}
					puts("");
				}
				puts("");*/
			}
		}
	}
	/*
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%d",mp[i][j]);
		}
		puts("");
	}
	*/
	int ans;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(mp[i][j]==1)
			{
				ans=BFS2(i,j);
				break;
			}
		}
	}
	printf("%d\n",ans);
 	return 0;
}

