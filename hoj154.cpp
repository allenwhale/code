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
const int MAXN=sqrt(80000)+10;
int s[80010];
int val[80010];
int d[MAXN][MAXN];
int cnt[10010],q[80010],rt[80010],sum[80010],ef[80010];
int F[10000][MAXN];
int st[MAXN],ed[MAXN];
int N,Q,sz,all,num;
void read()
{
	N=getint();Q=getint();
	for(int i=1;i<=N;i++)
		val[i]=s[i]=getint();
	sort(s+1,s+1+N);
	num=unique(s+1,s+1+N)-s-1;
	MS(cnt,0);
	for(int i=1;i<=N;i++)val[i]=lower_bound(s+1,s+1+num,val[i])-s;
	for(int i=1;i<=N;i++)cnt[val[i]]++;
	for(int i=1;i<=num;i++)sum[i]=sum[i-1]+cnt[i];
	for(int i=1;i<=num;i++)rt[i]=sum[i-1];
	for(int i=1;i<=N;i++)ef[++rt[val[i]]]=i;
}
inline void block()
{
	sz=(int)sqrt(N);
	all=N/sz;
	for(int i=1;i<=all;i++)
	{
		st[i]=ed[i-1]+1;
		ed[i]=st[i]+sz-1;
	}
	if(ed[all]!=N)
	{
		all++;
		st[all]=ed[all-1]+1;
		ed[all]=N;
	}
	int ccnt=0;
	for(int i=1;i<=all;i++)
	{
		MS(cnt,0);
		ccnt=0;
		for(int j=i;j<=all;j++)
		{
			for(int k=st[j];k<=ed[j];k++)
			{
				cnt[val[k]]++;
				if(cnt[val[k]]>ccnt)ccnt=cnt[val[k]];
			}
			d[i][j]=ccnt;
		}
	}		
	for(int i=1;i<=all;i++)
	{
		for(int j=0;j<=num;j++)F[j][i]=F[j][i-1];
		for(int j=st[i];j<=ed[i];j++)F[val[j]][i]++;
	}
}
inline int force(int x,int y)
{
	MS(cnt,0);
	int ccnt=0;
	for(int i=x;i<=y;i++)
	{
		cnt[val[i]]++;
		if(cnt[val[i]]>ccnt)ccnt=cnt[val[i]];
	}
	return ccnt;
}
inline int getsum(int l,int r,int v)
{
	return F[v][r]-F[v][l-1];
}
inline int query(int x,int y)
{
	int bx=x/sz+(x%sz!=0);
	int by=y/sz+(y%sz!=0);
	if(bx==by||bx+1==by)return force(x,y);
	MS(cnt,0);
	int h=0;	
	for(int i=x;i<=ed[bx];i++)
	{
		cnt[val[i]]++;
		if(cnt[val[i]]==1)q[h++]=val[i];
	}
	for(int i=st[by];i<=y;i++)
	{
		cnt[val[i]]++;
		if(cnt[val[i]]==1)q[h++]=val[i];
	}
	bx++,by--;
	int ccnt=d[bx][by];
	for(int i=0;i<h;i++)
	{		
		int bcnt=getsum(bx,by,q[i]);
		if(bcnt+cnt[q[i]]>ccnt)ccnt=bcnt+cnt[q[i]];
	}
	return ccnt;
}
int main()
{
	read();
	block();
	for(int i=0;i<Q;i++)
	{
		int l=getint();
		int r=getint();
		if(l>r)swap(l,r);
		printf("%d\n",query(l,r));
	}
	return 0;
}


