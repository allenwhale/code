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
ll M;
ll pow(ll n,int p)
{
	if(p==0)return 1;
	if(p&1)return (n*pow(n,p-1))%M;
	ll t=pow(n,p/2);
	return (t*t)%M;
}
int main()
{
	ll b;
	int p;
	while(~scanf(__I64d"%d"__I64d,&b,&p,&M))
	{
		printf(__I64d"\n",pow(b,p));
	}
 	return 0;
}

