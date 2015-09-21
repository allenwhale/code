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
struct E
{
	int to,vis;
	E(){}
	E(int _t,int _v)
	{
		to=_t,vis=_v;
	}
}e[200010*2];
vector<int>vc[50010];
int in[50010];
int cnte=0;
void add(int a,int b)
{
	vc[a].PB(cnte);
	e[cnte++]=E(b,0);
	vc[b].PB(cnte);
	e[cnte++]=E(a,0);
}
vector<int>euler;
void dfs(int x)
{
	foreach(it,vc[x])
	{
		if(e[*it].vis==0)
		{
			e[*it].vis=e[*it^1].vis=1;
			dfs(e[*it].to);
			euler.PB(*it);
		}
	}
}
int N,M;
int main()
{
	N=getint();
	M=getint();
	for(int i=0;i<M;i++)
	{
		int a=getint(),b=getint();
		add(a,b);
		in[a]++;in[b]++;
	}
	int x=0;
	for(int i=1;i<=N;i++)
		if(in[i]&1)x=i;
	dfs(x);
	foreach(it,euler)
	{
		printf("%d %d\n",e[*it].to,e[*it^1].to);
	}
	return 0;
}


