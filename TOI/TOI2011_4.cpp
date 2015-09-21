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
int in[110][110],out[110][110];
int N,M,P;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N,&M,&P);
		MS(in,-1);
		MS(out,0x3f);
		for(int i=0;i<M;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			scanf("%d %d",&in[a][b],&out[a][b]);
		}
		for(int k=1;k<=N;k++)
		{
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=N;j++)
				{
					if(i==k||j==k)continue;
					int tin=in[i][k]+in[k][j],tout=out[i][k]+out[k][j];
					if((db)tin/(db)tout>(db)in[i][j]/(db)out[i][j])
					{
						in[i][j]=tin;
						out[i][j]=tout;
					}
				}
			}
		}
		bool tf=false;
		for(int i=1;i<=N;i++)
		{
			//printf(" %d in %d out %d\n",i,in[i][i],out[i][i]);
			if((db)in[i][i]/(db)out[i][i]>(db)P)tf=true;
		}
		if(tf)puts("Yes");
		else puts("No");
	}
 	return 0;
}

