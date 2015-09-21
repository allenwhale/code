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
struct book
{
	int pr,af;
	bool operator < (const book& n)const
	{
		return af>n.af;
	}
}b[1010];
int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&b[i].pr,&b[i].af);
		}
		sort(b,b+N);
		int ti=0;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			ti+=b[i].pr;
			//printf(" %d %d %d\n",ti,b[i].pr,b[i].af);
			ans=max(ans,ti+b[i].af);
		}
		printf("%d\n",ans);
	}
 	return 0;
}

