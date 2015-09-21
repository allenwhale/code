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
#define MAXN 30
int path[MAXN][MAXN][MAXN];
db prof[MAXN][MAXN][MAXN];
int N;
deque<int>dq;

int main()
{
	while(~scanf("%d",&N))
	{
		MS(prof,0);
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(i==j)prof[0][i][j]=1.0;
				else scanf("%lf",&prof[0][i][j]);
				path[0][i][j]=i;
			}
		}
		for(int sp=1;sp<=N;sp++)
		{
			for(int k=1;k<=N;k++)
			{
				for(int i=1;i<=N;i++)
				{
					for(int j=1;j<=N;j++)
					{
						db tmp=prof[sp-1][i][k]*prof[0][k][j];
						if(tmp>prof[sp][i][j])
						{
							prof[sp][i][j]=tmp;
							path[sp][i][j]=k;
						}
					}
				}
			}
		}
		int fr,to,steps=-1;
		for(int sp=1;sp<=N&&steps==-1;sp++)
		{
			for(int i=1;i<=N&&steps==-1;i++)
			{
				if(prof[sp][i][i]>1.01)
				{
					fr=i,to=i,steps=sp;
				}			
			}
		}
		if(steps==-1)puts("no arbitrage sequence exists");
		else
		{
			//printf("%d %d\n",fr,to);
			//back(steps,fr,to);
			printf("%d ",fr);
			for(int sp=steps;sp>0;sp--)
			{
				dq.PF(path[sp][fr][to]);
				to=path[sp][fr][to];
			}
			for(int i=0;i<steps;i++)printf("%d ",dq[i]);
			printf("%d\n",fr);
		}
	}
 	return 0;
}

