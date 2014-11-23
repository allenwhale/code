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
struct R
{
	int to,w;
	inline R(){}
	inline R(int _t,int _w)
	{
		to=_t,w=_w;
	}
	inline bool operator < (const R &n)const
	{
		return n.w>w;
	}
};
vector<R>vc[100010];
int N,M,K,S;
int MIN,CNT;
void dfs(int x,int c)
{
	//if(c>MIN)return;
	CNT++;
	if(CNT>=K)return;
	foreach(it,vc[x])
	{
		if(c+it->w<=MIN)dfs(it->to,c+it->w);
		else break;
		if(CNT>K)break;
	}
}
void init()
{
	for(int i=0;i<=N;i++)vc[i].clear();
}
int main()
{
	while(~scanf("%d %d %d %d",&N,&M,&K,&S))
	{
		init();
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			vc[a].push_back(R(b,c));
		}
		for(int i=1;i<=N;i++)
			sort(vc[i].begin(),vc[i].end());
		int L=-1,R=INF;
		while(L+1!=R)
		{
			int mid=(L+R)/2;			
			CNT=0;
			MIN=mid;
			dfs(S,0);
			if(CNT>=K)R=mid;
			else L=mid;
		}
		printf("%d\n",R);
	}
	return 0;
}

