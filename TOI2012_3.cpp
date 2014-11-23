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
ll dis[510][510];
ll d[510];
int N;
ll MST()
{
	queue<int>q;
	q.push(1);
	d[1]=0;
	MS(d,0x3f);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if(i==t)continue;
			if(d[i]>dis[t][i])
			{
				d[i]=dis[t][i];
				q.push(i);
			}
		}
	}
	return d[N];
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf(__I64d,&dis[i][j]);
		}
	}
	printf(__I64d"\n",MST());
 	return 0;
}

