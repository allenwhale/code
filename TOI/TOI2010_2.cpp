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
vector<int>vc[1010];
int N;
int pre[1010];
int day[1010];
int in[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		MS(in,0);
		for(int i=1;i<=N;i++)vc[i].clear();
		for(int i=1;i<=N;i++)
		{
			int sz;
			scanf("%d %d",&day[i],&sz);
			for(int j=0;j<sz;j++)
			{
				int t;
				scanf("%d",&t);
				in[t]++;
				vc[i].PB(t);
			}
		}
		MS(pre,0);
		int ans=-1;
		while(true)
		{
			int v=-1;
			for(int i=1;i<=N&&v==-1;i++)
			{
				if(in[i]==0)v=i;
			}
			if(v==-1)break;
			in[v]=-1;
			//printf(" %d %d %d\n",v,pre[v],day[v]);
			day[v]+=pre[v];
			ans=max(ans,day[v]);
			int sz=vc[v].size();
			for(int i=0;i<sz;i++)
			{
				int t=vc[v][i];
				in[t]--;
				pre[t]=max(pre[t],day[v]);
			}
		}
		printf("%d\n",ans);
	}
 	return 0;
}

