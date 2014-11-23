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
deque<int>dq[30],wr[30];
bool vis[30][30];
int N,C;
PI q[1000];
int qf,qb;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool isin(int x,int y)
{
	return x>=0&&x<N&&y>=0&&y<N;
}
int BFS(int x,int y)
{
	vis[x][y]=true;
	qf=qb=0;
	q[qb++]=MP(x,y);
	int cnt=0;
	int c=dq[x][y];
	while(qb>qf)
	{
		PI t=q[qf++];
		cnt++;
		for(int i=0;i<4;i++)
		{
			int tx=t.FF+dx[i],ty=t.SS+dy[i];
			if(isin(tx,ty)&&!vis[tx][ty]&&c==dq[tx][ty])
			{
				vis[tx][ty]=true;
				q[qb++]=MP(tx,ty);
			}
		}
	}
	return cnt;
}
bool v[30][30];
int BFS2(int x,int y)
{
	qf=qb=0;
	q[qb++]=MP(x,y);
	v[x][y]=true;
	int cnt=0;
	int c=wr[x][y];
	while(qb>qf)
	{
		PI t=q[qf++];
		cnt++;
		for(int i=0;i<4;i++)
		{
			int tx=t.FF+dx[i],ty=t.SS+dy[i];
			if(isin(tx,ty)&&!v[tx][ty]&&c!=0&&c==wr[tx][ty])
			{
				v[tx][ty]=true;
				q[qb++]=MP(tx,ty);
			}
		}
	}
	return cnt;
}
void init()
{
	for(int i=0;i<N;i++)
	{
		wr[i]=dq[i];
	}
	for(int i=0;i<qb;i++)
	{
		int x=q[i].FF,y=q[i].SS;
		wr[x].erase(wr[x].begin()+y);
	}
	for(int i=0;i<N;i++)
	{
		while(wr[i].size()<N)wr[i].PB(0);
	}
}
int main()
{
	scanf("%d %d",&N,&C);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			int idx;
			scanf("%d",&idx);
			dq[j].PF(idx);
		}
	}
	/*
	puts("");
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",dq[i][j]);
		}
		puts("");
	}*/
	int ans=-1;
	MS(vis,false);
//	BFS(0,2);
//	init();
//	puts("");
//	for(int i=0;i<N;i++)
//	{
//		for(int j=0;j<N;j++)
//		{
//			printf("%d ",wr[i][j]);
//		}
//		puts("");
//	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!vis[i][j])
			{
				int a=BFS(i,j);
				init();
				MS(v,false);
				for(int k=0;k<N;k++)
				{
					for(int l=0;l<N;l++)
					{
						if(!v[k][l]&&wr[k][l]!=0)
						{
							int b=BFS2(k,l);
							//printf("%d %d %d %d %d %d\n",i,j,k,l,a,b);
							ans=max(ans,a*a+b*b);
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
 	return 0;
}

