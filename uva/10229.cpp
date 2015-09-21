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
int MOD;
struct mat
{
	/*
	a b
	c d
	*/
	ll a,b,c,d;
	mat(){}
	mat(ll _a,ll _b,ll _c,ll _d)
	{
		a=_a,b=_b,c=_c,d=_d;
	}
		
};
mat crs(mat a,mat b)
{
	mat res;
	res.a=a.a*b.a+a.b*b.c;
	res.b=a.a*b.b+a.b*b.d;
	res.c=a.c*b.a+a.d*b.c;
	res.d=a.c*b.b+a.d*b.d;
	res.a%=MOD;
	res.b%=MOD;
	res.c%=MOD;
	res.d%=MOD;
	return res;
}
int main()
{
	
	
	ll n;
	int m;
	while(~scanf(__I64d" %d",&n,&m))
	{
		mat res=mat(1,0,0,1);
		mat f=mat(0,1,1,1);
		MOD=1<<m;
		for(ll i=0;n>=(1LL<<i);i++)
		{
			//printf("in %d\n",i);
			if(n&(1<<i))res=crs(res,f);
			f=crs(f,f);
		}
		//printf(" %d %d %d %d\n",res.a,res.b,res.c,res.d);
		printf(__I64d"\n",res.b);
	}
 	return 0;
}

