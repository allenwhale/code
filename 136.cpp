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
int pr[]={2,3,5};
int prd[]={0,0,0};
int un[1510],und=0;
int main()
{
	un[und++]=1;
	un[und++]=2;
	un[und++]=3;
	un[und++]=4;
	for(int i=0;i<1500;i++)
	{
		int mn=0x3fffffff;
		for(int j=0;j<3;j++)
		{
			while(pr[j]*un[prd[j]]<=un[und-1])
				prd[j]++;
			mn=min(mn,pr[j]*un[prd[j]]);
			//printf(" %d\n",pr[j]*un[prd[j]]);
		}
		un[und++]=mn;
		//printf("%d %d\n",und-1,un[und-1]);
	}
	printf("%d\n",un[1499]);
 	return 0;
}

