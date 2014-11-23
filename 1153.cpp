#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PPF(a) push_front(a)
#define PF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
struct W
{
	int d,t;
	bool operator < (const W &n)const
	{
		return d<n.d;
	};
}s[800010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d %d",&s[i].t,&s[i].d);
		sort(s,s+N);
		priority_queue<int,vector<int>,less<int> >pq;
		int now=0;
		for(int i=0;i<N;)
		{
			int d=s[i].d;
			while(i<N&&s[i].d==d)pq.push(s[i].t),now+=s[i].t,i++;
			while(now>d)
			{
				int tmp=pq.top();
				//printf("out %d\n",tmp);
				pq.pop();
				now-=tmp;
			}
		}
		printf("%d\n",SIZE(pq));
		if(T)puts("");
	}
	return 0;
}

