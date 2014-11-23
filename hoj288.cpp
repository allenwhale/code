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
int N,M,L;
vector<E>vc[100010];
bool vis[100010];
int D,MD,P;
void dfs1(int x,int px,int d)
{
	//printf(" %d\n",x);
	if(d>D)
	{
		D=d,P=x;
	}
	vis[x]=true;
	foreach(it,vc[x])
	{
		if(it->to!=px)
		{
			dfs1(it->to,x,d+it->c);
		}
	}
}
bool dfs2(int x,int px,int d)
{
	if(d==D)return true;
	foreach(it,vc[x])
	{
		if(it->to!=px)
		{
			if(dfs2(it->to,x,d+it->c))
			{
				MD=min(MD,max(D-d,d));
				return true;
			}
		}
	}
	return false;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	N=getint();
	M=getint();
	L=getint();
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		a=getint();
		b=getint();
		c=getint();
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	MS(vis,false);
	vector<int>tmp;
	int LD=0;
	for(int i=0;i<N;i++)
	{
		if(vis[i]==false)
		{
			D=INT_MIN,MD=INT_MAX;
			dfs1(i,i,0);
			//puts("");
			dfs1(P,P,0);
			dfs2(P,P,0);
			LD=max(LD,D);
			if(MD==INT_MAX)MD=0;
			tmp.PB(MD);
			//printf("%d %d %d\n\n",i,D,MD);
		}
	}
	sort(tmp.begin(),tmp.end(),cmp);
	if(SIZE(tmp)==1)printf("%d\n",max(tmp[0],LD));
	else if(SIZE(tmp)==2)printf("%d\n",max(tmp[0]+tmp[1]+L,LD));
	else
		printf("%d\n",max(min(max(tmp[0]+tmp[1]+L,tmp[1]+tmp[2]+2*L),max(tmp[0]+tmp[1]+L,tmp[0]+tmp[2]+2*L)),LD));
	return 0;
}


