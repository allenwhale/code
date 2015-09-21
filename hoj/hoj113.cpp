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
#include <set>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,eit,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
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
	int to,w;
	E(){}
	E(int _t,int _w)
	{
		to=_t,w=_w;
	}
};
vector<E>vc[100010];
int N,M;
int ch[100010],p[100010];
bool vvis[100010];
int alln;
inline void init()
{
	for(int i=0;i<N;i++)
	{
		vc[i].clear();
	}
	MS(vvis,false);
}
void dfs1(int x,int px)
{
	ch[x]=1;p[x]=px;
	foreach(it,eit,vc[x])
	{
		if(it->to!=px&&!vvis[it->to])
		{
			dfs1(it->to,x);
			ch[x]+=ch[it->to];
		}
	}
}
pI dfs2(int x,int px)
{
	pI res(0,x);
	foreach(it,eit,vc[x])
	{
		if(!vvis[it->to])res.FF=max(res.FF,it->to==p[x]?alln-ch[x]:ch[it->to]);
	}
	foreach(it,eit,vc[x])
	{
		if(it->to!=px&&!vvis[it->to])
			res=min(res,dfs2(it->to,x));
	}
	return res;
}
inline int findcenter(int x)
{
	dfs1(x,x);
	alln=ch[x];
	return dfs2(x,x).SS;
}
void fill(vector<int> &v,int x,int d,int px)
{
	v.PB(d);
	foreach(it,eit,vc[x])
	{
		if(it->to!=px&&!vvis[it->to])
			fill(v,it->to,(d+it->w)%M,x);
	}
}
int solve(int x)
{
	int ans=0;
	x=findcenter(x);
	vvis[x]=true;
	set<int>s;
	s.insert(0);
	foreach(it,eit,vc[x])
	{
		vector<int>tmp;
		if(!vvis[it->to])fill(tmp,it->to,it->w,it->to);
		foreach(jt,ejt,tmp)
		{
			ans=max(ans,max((*--s.end()+*jt)%M,*--s.lower_bound(M-*jt)+*jt));
		}
		foreach(jt,ejt,tmp)s.insert(*jt);
	}
	foreach(it,eit,vc[x])
	{
		if(!vvis[it->to])ans=max(ans,solve(it->to));
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d %d",&N,&M);
		for(int i=0;i<N-1;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			a--,b--;
			vc[a].PB(E(b,c%M));
			vc[b].PB(E(a,c%M));
		}
		printf("%d\n",solve(0));
	}
	return 0;
}

