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
int N;
ll s[40];
set<ll>st;
bool tf=false;
void dfs1(int l,int r,ll add,int n)
{
	if(tf)return;
	if(l>r)
	{
		if(n>0)
		{
			if(add==0&&n>0)tf=true;
			else st.insert(add);
		}
		return;
	}
	dfs1(l+1,r,add+s[l],n+1);
	dfs1(l+1,r,add,n);
}
void dfs2(int l,int r,ll add,int n)
{
	if(tf)return ;
	if(l>r)
	{
		if(add==0&&n>0)tf=true;
		else tf|=(st.find(-add)!=st.end());
		//if(tf)printf(" %d\n",add);
		return;
	}
	dfs2(l+1,r,add+s[l],n+1);
	dfs2(l+1,r,add,n);
}
int main()
{
	N=getint();
	for(int i=0;i<N;i++)
	{
		s[i]=getll();
	}
	dfs1(0,N/2,0,0);
	if(tf)
	{
		puts("yes");
		return 0;
	}
	dfs2(N/2+1,N-1,0,0);
	if(tf)puts("yes");
	else puts("no");
	return 0;
}


