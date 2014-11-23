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
ll s[30];
int N;
struct point
{
	ll x,y;
	int k;
	point(){}
	point(ll _x,ll _y,int _k)
	{
		x=_x,y=_y,k=_k;
	}
	bool operator < (const point &n)const
	{
		if(n.y==y)return !n.x<x;
		return !n.y<y;
	}
};
struct point2
{
	ll x,y;
	point2(){}
	point2(ll _x,ll _y)
	{
		x=_x,y=_y;
	}
	bool operator < (const point2 &n)const
	{
		if(n.x==x)return !n.x+n.y>x+y;
		return !n.x>x;
	}
};
set<point>KL;
set<point2>S;
void dfs1(int l,int r,int an,ll as,int bn,ll bs,int cn,ll cs,int k)
{
	if(l>r)
	{
		if(as>=bs&&bs>=cs)
		{
			printf(" %d\n",k);
			if(k==0)
			{
				KL.insert(point(as-bs,bs-cs,k));
				printf(" %I64d %I64d %d\n",as-bs,bs-cs,k);
			}
			else 
			{
				KL.insert(point(bs-as,cs-bs,k));
				printf(" %I64d %I64d %d\n",bs-as,cs-bs,k);
			}
		}
		return ;
	}
	dfs1(l+1,r,an+1,as+s[l],bn,bs,cn,cs,k);
	dfs1(l+1,r,an,as,bn+1,bs+s[l],cn,cs,k);
	dfs1(l+1,r,an,as,bn,bs,cn+1,cs+s[l],k);
}
int main()
{
	N=getint();
	for(int i=0;i<N;i++)
		s[i]=getll();
	dfs1(0,N/2,0,0,0,0,0,0,0);
	dfs1(N/2+1,N-1,0,0,0,0,0,0,1);
	ll ans=INF;
	foreach(it,KL)
	{
		printf("%I64d %I64d %d\n",it->x,it->y,it->k);
		if(it->k==1)
		{
			set<point2>::IT iit=S.lower_bound(point2(it->x,it->y));
			ans=min(ans,abs((it->x+it->y)-(iit->x+iit->y)));
		}
		else
		{
			if(SIZE(S)==0)S.insert(point2(it->x,it->y));
			else 
			{
				S.erase(*S.lower_bound(point2(it->x,it->y)));
				S.insert(point2(it->x,it->y));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}


