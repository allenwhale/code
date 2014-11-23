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
int cnt=0;
typedef vector<vector<int> > vII;
vII ans[1010];
vector<int> make_vc(int x)
{
	vector<int>vc;
	for(int i=1;i<=x;i++)
		vc.PB(i);
	return vc;
}
vector<int> combine(vector<int> a,vector<int> b,int x)
{
	vector<int>vc=a;
	foreach(it,b)
		vc.PB(*it+x);
	return vc;
}
void dfs(int n)
{
	if(ans[n].size()||n==1)return;
	int x=n/2+(n&1),y=n/2;
	dfs(x);dfs(y);
	vII &s=ans[n];
	vII &a=ans[x];
	vII &b=ans[y];
	s.PB(make_vc(x));
	int len=min(SIZE(a),SIZE(b));
	for(int i=0;i<len;i++)
		s.PB(combine(a[i],b[i],x));
	for(int i=len;i<SIZE(a);i++)
		s.PB(a[i]);
}
int main()
{
	N=getint();
	dfs(N);
	printf("%d\n",SIZE(ans[N]));
	for(int i=0;i<SIZE(ans[N]);i++)
	{
		vector<int> t=ans[N][i];
		printf("%d",SIZE(t));
		for(int j=0;j<SIZE(t);j++)
		{
			printf(" %d",t[j]);
		}
		puts("");
	}
	return 0;
}


