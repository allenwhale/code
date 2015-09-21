#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PPF(a) push_front(a)
#define PF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
struct SEG
{
	int l,r,s;
	SEG()
	{
		l=r=s=-1;
	}
}seg[4000010];
void update(int idx,int k,int v)
{
	if(seg[idx].l==seg[idx].r)
	{
		seg[idx].s=v;
		return ;
	}
	int mid=(seg[idx].l+seg[idx].r)>>1;
	if(k<=mid)update(idx<<1,k,v);
	else update((idx<<1)|1,k,v);
	seg[idx].s=min(seg[idx<<1].s,seg[(idx<<1)|1].s);
}
int query(int idx,int l,int r)
{
	if(seg[idx].l==l&&seg[idx].r==r)return seg[idx].s;
	int mid=(seg[idx].l+seg[idx].r)>>1;
	if(r<=mid)return query(idx<<1,l,r);
	else if(mid<l)return query((idx<<1)|1,l,r);
	else return min(query(idx<<1,l,mid),query((idx<<1)|1,mid+1,r));
}
void build(int idx,int l,int r)
{
	seg[idx].l=l,seg[idx].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(idx<<1,l,mid);
	build((idx<<1)|1,mid+1,r);
}
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	build(1,0,M);
	for(int i=0;i<M;i++)
	{
		int k;
		scanf("%d",&k);
		update(1,i,k);
	}
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)printf("%d\n",query(1,b,c));
		else update(1,b,c);
	}
	return 0;
}

