#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <complex>
#include <functional>
#include<bits/stdc++.h>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>tmap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>tset;
inline int getint()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	int x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
inline ll getll()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	ll x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
struct E
{
	int to,c;
	E(){}
	E(int _t,int _c)
	{
		to=_t,c=_c;
	}
};
int N,M;
vector<E>vc[100010];
int pa[100010];
int dth[100010];
int lca[100010][20];
void dfs(int x,int px,int d)
{
	pa[x]=px,dth[x]=d;
	lca[x][0]=px;
	for(int i=1;i<20;i++)
		lca[x][i]=lca[lca[x][i-1]][i-1];
	foreach(it,vc[x])
	{
		if(it->to!=px)
		{
			dfs(it->to,x,d+it->c);
		}
	}
}
int LCA(int x,int k)
{
	int res=0;
	for(int i=19;i>=0;i--)
	{
		if(k>=(1<<i))
		{
			k-=(1<<i);
			res+=dth[x]-dth[lca[x][i]];
			x=lca[x][i];
		}
	}
	return res;
}
int main()
{
	N=getint();
	M=getint();
	for(int i=0;i<N-1;i++)
	{
		int a=getint(),b=getint(),c=getint();
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	dfs(1,1,0);
	for(int i=0;i<M;i++)
	{
		int a=getint(),b=getint();
		printf("%d\n",LCA(a,b));
	}
	return 0;
}


