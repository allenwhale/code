#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
int deg[210],p[210];
int N,M;
void init()
{
	for(int i=0;i<210;i++)p[i]=i;
	MS(deg,0);
}
int find(int a)
{
	return a==p[a]?a:p[a]=find(p[a]);
}
void U(int a,int b)
{
	p[find(b)]=find(a);
}
int main()
{
	while(~scanf("%d %d",&N,&M))
	{
		init();
		int st=-1;
		for(int i=0;i<M;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			st=a;
			U(a,b);
			deg[a]++,deg[b]++;
		}
		bool tf=true;
		for(int i=0;i<N;i++)
		{
			if(deg[i]&1||find(i)!=find(st))tf=false;
		}
		if(tf)puts("Possible");
		else puts("Not Possible");
	}
	return 0;
}

