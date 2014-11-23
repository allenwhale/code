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
vector<int>vc[100010];
int N,M;
int top[100010],son[100010],dth[100010],ti[100010],pa[100010],sz[100010],tn=1;
int w[100010],wi[100010];
void dfs1(int x,int p)
{
	sz[x]=1,dth[x]=dth[p]+1,pa[x]=p,son[x]=0;
	foreach(it,vc[x])
	{
		if(*it!=p)
		{
			dfs1(*it,x);
			sz[x]+=sz[*it];
			if(sz[*it]>sz[son[x]])
				son[x]=*it;
		}
	}
}
void dfs2(int x,int p)
{
	top[x]=p;ti[x]=tn++;
	if(son[x]!=0)dfs2(son[x],p);
	foreach(it,vc[x])
	{
		if(*it!=pa[x]&&*it!=son[x])
			dfs2(*it,*it);
		w[*it]=*it;
	}
}
struct Seg
{
	int L,R,val,mark;
	Seg(){}
	Seg(int l,int r)
	{
		L=l,R=r,val=mark=0;
	}
}s[400010];
void pushdown(int idx)
{
	if(s[idx].L==s[idx].R||s[idx].mark==0)
	{
		s[idx].mark=0;
		return ;	
	}
	//int mid=(s[idx].L+s[idx].R)>>1;
	int c=s[idx].mark;
	s[idx].mark=0;
	s[idx<<1].mark+=c,s[idx<<1].val+=c*(s[idx<<1].R-s[idx<<1].L+1);
	s[idx<<1|1].mark+=c,s[idx<<1|1].val+=c*(s[idx<<1|1].R-s[idx<<1|1].L+1);
}
void build(int l,int r,int idx)
{
	s[idx]=Seg(l,r);
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,idx<<1);
	build(mid+1,r,idx<<1|1);
}
void insert(int idx,int l,int r,int c)
{
	//printf(" i %d %d %d %d %d\n",idx,l,r,s[idx].L,s[idx].R);
	s[idx].val+=c*(r-l+1);
	if(s[idx].L==l&&s[idx].R==r)
	{
		s[idx].mark+=c;
		return;
	}
	if(s[idx].L==s[idx].R)return ;
	int mid=(s[idx].L+s[idx].R)>>1;
	if(r<=mid)insert(idx<<1,l,r,c);
	else if(mid+1<=l)insert(idx<<1|1,l,r,c);
	else 
	{
		insert(idx<<1,l,mid,c);
		insert(idx<<1|1,mid+1,r,c);
	}
}
void paint(int x,int y)
{
	while(top[x]!=top[y])
	{
		
		if(dth[top[x]]<dth[top[y]])swap(x,y);
		//printf("%d\n",x);
		if(x!=top[x])insert(1,ti[top[x]],ti[x],1);
		x=top[x];
		if(w[x])wi[w[x]]++,x=pa[x];
		//puts("");
	}
	//printf("%d %d\n",x,y);
	if(x==y)return;
	if(dth[x]>dth[y])swap(x,y);
	insert(1,ti[x]+1,ti[y],1);
}
int query(int idx,int l,int r)
{
//	printf(" q %d %d %d %d %d\n",idx,l,r,s[idx].L,s[idx].R);
	pushdown(idx);
	if(s[idx].L==l&&s[idx].R==r)
		return s[idx].val;	
	int mid=(s[idx].L+s[idx].R)>>1;
	if(r<=mid)return query(idx<<1,l,r);
	else if(mid+1<=l)return query(idx<<1|1,l,r);
	else return query(idx<<1,l,mid)+query(idx<<1|1,mid+1,r);
}
int find(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		//printf(" Q %d %d\n",x,y);
		if(dth[top[x]]<dth[top[y]])swap(x,y);
		if(x!=top[x])ans+=query(1,ti[top[x]],ti[x]);
		x=top[x];
		if(w[x])ans+=wi[w[x]],x=pa[x];
		//printf("ans %d\n",ans);
	}
	//printf("%d %d\n",x,y);
	if(x==y)return ans;
	if(dth[x]>dth[y])swap(x,y);
	ans+=query(1,ti[x]+1,ti[y]);
	return ans;
}
int main()
{
	N=getint();
	M=getint();
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		a=getint();
		b=getint();
		vc[a].PB(b);
		vc[b].PB(a);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,N,1);
	//for(int i=1;i<=N;i++)
	//	printf("%d %d %d\n",ti[i],top[i],pa[i]);
		
	for(int i=0;i<M;i++)
	{
		char tmp[2];
		int a,b;
		scanf("%s",tmp);
		a=getint();
		b=getint();
		if(tmp[0]=='P')
		{
			paint(a,b);
		}
		else if(tmp[0]=='Q')
		{
			printf("%d\n",find(a,b));
		}
	}
	//while(1);
	return 0;
}


