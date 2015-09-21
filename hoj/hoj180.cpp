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
//#include<bits/stdc++.h>
//#include<ext/rope>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
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
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
//typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>tmap;
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
int N,M;
vector<int>vc[50010];
bool vis[50010];
int c[50010];
bool is[50010];
int L;
int cnt=0;
int tmp=1;
int id=0;
void dfs(int x,int d)
{
	//printf(" %d\n",x);
	vis[x]=true;c[d]=	x;
	if(is[x])
	{	
		if(d>L)L=d,id=x;
		if(d%2!=(L/2)%2)tmp=0;
		cnt++;
	}
	foreach(it,vc[x])
	{
		if(vis[*it]==false)dfs(*it,d+1);
	}
}
int main()
{
	N=getint();
	M=getint();
	for(int i=0;i<M;i++)
	{
		int a=getint(),b=getint();
		vc[a].PB(b);
		vc[b].PB(a);
	}
	int K=getint();
	int t=0;
	for(int i=0;i<K;i++)
	{
		is[t=getint()]=true;
	}
	MS(vis,false);
	L=0;
	dfs(t,0);
	MS(vis,false);
	L=0;
	dfs(id,0);
	MS(vis,false);
	cnt=0;tmp=1;
	dfs(c[L/2],0);
	if((L&1)||(tmp==0)||(cnt!=K))puts("NIE");
	else printf("%d\n",L/2);
	//printf("%d %d %d\n",L,tmp,cnt);
	return 0;
}


