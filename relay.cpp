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
#define MAXV 1010
int g[MAXV];
int pos[MAXV];
bool vis[MAXV];
/*
-1 nloop
0 nvis
1 loop
*/
int N;
bool DFS(int x)
{
	//printf(" %d\n",x);
	if(g[x]==0)
	{
		pos[x]=-1;
		return false;
	}
	if(pos[x]==1)return true;
	if(pos[x]==-1)return false;
	if(vis[x])
	{
		pos[x]=1;
		return true;
	}
	vis[x]=true;
	bool tf=DFS(g[x]);
	if(tf)pos[x]=1;
	else pos[x]=-1;
	return tf;
}
int main()
{
	freopen("relay.in","r",stdin);
	freopen("relay.out","w",stdout);
	MS(pos,0);
	scanf("%d\n",&N);
	for(int i=1;i<=N;i++)scanf("%d",&g[i]);
	for(int i=1;i<=N;i++)
	{
		if(pos[i]==0)
		{
			MS(vis,false);
			DFS(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=N;i++)
	{
		if(pos[i]==-1)cnt++;
	}
	printf("%d\n",cnt);
 	return 0;
}

