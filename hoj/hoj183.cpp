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
struct Seg
{
	int l,r,mx,mn;
	Seg(){}
	Seg(int _l,int _r)
	{
		l=_l,r=_r;
		mx=INT_MIN;
		mx=INT_MAX;
	}
}s[200020];
void build(int idx,int l,int r)
{
	s[idx]=Seg(l,r);
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
}
void update(int idx,int x,int v)
{
	if(s[idx].l==s[idx].r&&s[idx].l==x)
	{
		s[idx].mn=s[idx].mx=v;
		return ;
	}
	int mid=(s[idx].l+s[idx].r)>>1;
	if(x<=mid)update(idx<<1,x,v);
	else update(idx<<1|1,x,v);
	s[idx].mn=min(s[(idx<<1)].mn,s[(idx<<1)|1].mn);
	s[idx].mx=max(s[idx<<1].mx,s[(idx<<1)|1].mx);
}
int querymx(int idx,int l,int r)
{
	
	if(s[idx].l==l&&s[idx].r==r)
		return s[idx].mx;
	
	int mid=(s[idx].l+s[idx].r)>>1;
	//printf("mx %d %d %d %d %d %d\n",idx,l,r,s[idx].l,s[idx].r,mid);
	if(r<=mid)return querymx(idx<<1,l,r);
	else if(l>=mid+1)return querymx((idx<<1)|1,l,r);
	else return max(querymx(idx<<1,l,mid),querymx((idx<<1)|1,mid+1,r));
}
int querymn(int idx,int l,int r)
{
	if(s[idx].l==l&&s[idx].r==r)
		return s[idx].mn;
	int mid=(s[idx].l+s[idx].r)>>1;
	if(r<=mid)return querymn(idx<<1,l,r);
	else if(l>=mid+1)return querymn(idx<<1|1,l,r);
	else return min(querymn(idx<<1,l,mid),querymn(idx<<1|1,mid+1,r));
}
inline int query(int l,int r)
{
	return querymx(1,l,r)-querymn(1,l,r);
}
int N,Q;

int main()
{
	N=getint();
	Q=getint();
	build(1,1,N);
	for(int i=1;i<=N;i++)
		update(1,i,getint());
	for(int i=0;i<Q;i++)
	{
		int l=getint(),r=getint();
		printf("%d\n",query(l,r));
	}
	return 0;
}


