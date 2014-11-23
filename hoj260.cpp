#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
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
struct E
{
	int to,c;
	E(){}
	E(int _t,int _c)
	{
		to=_t,c=_c;
	}
};
vector<E>vc[200010];
int N,K;
int ch[200010],allc;
bool vvis[200010];
int pa[200010];
int ans=INF;
int dth[1000010];
int cnt[1000010];
int cur=0;
void dfs1(int x,int px)
{	
	ch[x]=1;
	pa[x]=px;
	foreach(it,vc[x])
	{
		if(it->to!=px&&vvis[it->to]==false)
		{
			dfs1(it->to,x);
			ch[x]+=ch[it->to];
		}
	}
}
pI dfs2(int x,int px)
{
	pI res=MP(0,x);
	foreach(it,vc[x])
	{
		if(vvis[it->to]==false)
		{
			res.FF=max(res.FF,it->to==pa[x]?allc-ch[x]:ch[it->to]);
		}
	}
	foreach(it,vc[x])
	{
		if(it->to!=px&&vvis[it->to]==false)
		{
			res=min(dfs2(it->to,x),res);
		}
	}
	return res;
}
inline int findcenter(int x)
{
	dfs1(x,x);
	allc=ch[x];
	return dfs2(x,x).SS;
}
void dfs3(int x,int d,int n,int px)
{
	if(d>K)return;
	if(dth[K-d]==cur)ans=min(ans,n+cnt[K-d]);	
	foreach(it,vc[x])
	{
		if(it->to!=px&&vvis[it->to]==false)
		{
			dfs3(it->to,d+it->c,n+1,x);
		}
	}
}
void dfs4(int x,int d,int n,int px)
{
	if(d>K)return;
	if(dth[d]!=cur)
	{
		dth[d]=cur;
		cnt[d]=n;
	}
	else
	{
		cnt[d]=min(cnt[d],n);
	}
	foreach(it,vc[x])
	{
		if(it->to!=px&&vvis[it->to]==false)
		{
			dfs4(it->to,d+it->c,n+1,x);
		}
	}
}
void solve(int x)
{
	x=findcenter(x);
	cur=x+1;
	vvis[x]=true;
	dth[0]=cur;
	foreach(it,vc[x])
	{
		if(vvis[it->to]==false)
		{
			dfs3(it->to,it->c,1,it->to);
			dfs4(it->to,it->c,1,it->to);
		}
	}
	foreach(it,vc[x])
	{
		if(vvis[it->to]==false)solve(it->to);
	}
}
int main()
{
	scanf("%d %d",&N,&K);
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	solve(0);
	if(ans!=INF)printf("%d\n",ans);
	else puts("-1");
	return 0;
}

