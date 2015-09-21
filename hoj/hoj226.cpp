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
int N,K;
struct P
{
	int x,y;
	P(int _x,int _y)
	{
		x=_x,y=_y;
	}
	bool operator <(const P &n)const
	{
		return n.x>x;
	}
};
struct T
{
	int x,y,n,k;
	T(int _x,int _y,int _n,int _k)
	{
		x=_x,y=_y,n=_n,k=_k;
	}
	bool operator < (const T &a)const
	{
		if(a.x!=x)return a.x>x;
		return a.k<k;
	}
};
vector<T>vc;
bool in[1000010];
int main()
{
	N=getint();
	K=getint();
	for(int i=0;i<N;i++)
	{
		int a=getint(),b=getint();
		vc.PB(T(a,b,i,1));
		vc.PB(T(b,b,i,-1));
	}
	sort(vc.begin(),vc.end());
	__gnu_pbds::priority_queue<P>pq;
	int ans=0,add=0;
	MS(in,false);
	for(int i=0;i<N*2;i++)
	{
		//printf("%d\n",add);
		//printf("%d %d %d %d\n",vc[i].x,vc[i].y,vc[i].n,vc[i].k);
		if(vc[i].k==1)
		{
			pq.push(P(vc[i].y,vc[i].n));
			//in[vc[i].n]=true;
			add++;
		}
		else if(!in[vc[i].n])
		{
			//in[vc[i].n]=false;
			add--;
		}
		if(add==K)
		{
			ans++,add--;
			P out=pq.top();
			pq.pop();
			in[out.y]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}


