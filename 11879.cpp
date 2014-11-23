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
deque<int>dq;
void show()
{
	for(int i=dq.size()-1;i>=0;i--)
	{
		printf("%d",dq[i]);
	}
	puts("");
}
int main()
{
	char s[1000];
	while(gets(s)!=NULL)
	{
		dq.clear();
		int len=strlen(s);
		if(len==1&&s[0]=='0')break;
		for(int i=0;i<len;i++)
		{
			dq.PF(s[i]-'0');
		}
		while(dq.size()>10)
		{
			int d=dq[0];
			dq.PPF();
			d*=5;
			dq[0]-=d%10;
			dq[1]-=d/10;
			int sz=dq.size();
			for(int i=0;i<sz;i++)
			{
				if(dq[i]<0)
				{
					dq[i]+=10;
					dq[i+1]-=1;
				}
			}
			if(dq[sz-1]==0)dq.PPB();
			//show();
		}
		ll n=0;
		int sz=dq.size();
		for(int i=sz-1;i>=0;i--)
		{
			n*=10LL;
			n+=(ll)dq[i];
		}
		//printf(" "__I64d"\n",n);
		if(n%17LL==0)puts("1");
		else puts("0");
	}
 	return 0;
}

