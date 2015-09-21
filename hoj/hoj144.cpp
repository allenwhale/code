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
struct Treap
{
	Treap *L,*R;
	int key,pri,sz,big;
	Treap(int k=-INF)
	{
		big=key=k;
		L=R=NULL;
		sz=(k!=-INF);
		pri=rand();
	}
	void pull()
	{
		sz=(L?L->sz:0)+(R?R->sz:0)+1;
	}
};
int BIG(Treap *tr)
{
	return tr?tr->big:0;
}
int size(Treap *tr)
{
	return tr?tr->sz:0;
}
Treap* merge(Treap *a,Treap *b)
{
	if(!a||!b)return a?a:b;
	if(a->pri>=b->pri)
	{
		a->R=merge(a->R,b);
		a->pull();
		a->big=max(a->key,max(BIG(a->L),BIG(a->R)));
		return a;
	}
	else 
	{
		b->L=merge(a,b->L);
		b->pull();
		b->big=max(b->key,max(BIG(b->L),BIG(b->R)));
		return b;
	}
}
void spilt(Treap *tr,Treap* &l,Treap* &r,int k)
{
	if(tr==NULL)
	{
		l=r=NULL;
		return ;
	}
	if(size(tr->L)<k)
	{
		l=tr;
		spilt(tr->R,l->R,r,k-size(tr->L)-1);
		l->pull();
		l->big=max(l->key,max(BIG(l->L),BIG(l->R)));
	}
	else
	{
		r=tr;
		spilt(tr->L,l,r->L,k);
		r->pull();
		r->big=max(r->key,max(BIG(r->L),BIG(r->R)));
	}	
}
void insert(Treap* &tr,int x)
{
	Treap *t=new Treap(x);
	tr=merge(tr,t);
}
int ask(Treap *t,int l,int r)
{
	Treap *a,*b,*c,*d;
	spilt(t,a,b,l-1);
	spilt(b,d,c,r-l+1);
	int tmp=BIG(d);
	t=merge(a,merge(d,c));
	return tmp;
}
void modify(Treap* &tr,int k,int x)
{
	Treap *a,*b,*c;
	spilt(tr,a,b,k-1);
	spilt(b,c,b,1);
	tr=merge(a,merge(new Treap(x),b));
}
int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	Treap *root=NULL;
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	while(Q--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		{
			modify(root,b,c);
		}
		else if(a==2)
		{
			printf("%d\n",ask(root,b,c));
		}
	}
	return 0;
}

