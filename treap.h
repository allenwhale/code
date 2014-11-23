#ifndef __TREAP__H__
#define __TREAP__H__
#define treap Treap*
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
inline int getint()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	int x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
int Rand()
{
	srand((int)getint);
	return rand()*(rand()&1?-1:1);
}
struct Treap
{
	struct Treap *L,*R;
	int v,sum,sz;
	int cover,rev;
	int pri;
	int tmx,lmx,rmx;
	Treap(int k=-1)
	{
		v=tmx=lmx=rmx=sum=k;
		sz=1;cover=rev=0;
		pri=Rand();
		L=R=NULL;
	}
	inline void down()
	{
		if(rev)
		{
			rev=0;
			swap(L,R);
			if(L)L->rev^=1,swap(L->lmx,L->rmx);
			if(R)R->rev^=1,swap(R->lmx,R->rmx);
		}
		if(cover)
		{
			cover=0;
			if(L)
			{
				L->v=v;L->sum=v*L->sz;
				if(v>=0)L->tmx=L->lmx=L->rmx=L->sum;
				else L->tmx=L->lmx=L->rmx=v;
				L->cover=1;
			}
			if(R)
			{
				R->v=v;R->sum=v*R->sz;
				if(v>=0)R->tmx=R->lmx=R->rmx=R->sum;
				else R->tmx=R->lmx=R->rmx=v;
				R->cover=1;
			}
		}
	}
	inline void up()
	{
		//puts("up in");
		tmx=lmx=rmx=sum=v;sz=1;
		if(L)sum+=L->sum,sz+=L->sz;
		if(R)sum+=R->sum,sz+=R->sz;
		if(L)
		{
			lmx=L->lmx;
			lmx=max(lmx,L->sum+v);
			if(R)lmx=max(lmx,L->sum+v+R->lmx);
		}
		else if(R)
		{
			lmx=max(lmx,v+R->lmx);
		}
		if(R)
		{
			rmx=R->rmx;
			rmx=max(rmx,R->sum+v);
			if(L)rmx=max(rmx,R->sum+v+L->rmx);
		}
		else if(L)
		{
			rmx=max(rmx,L->rmx+v);
		}
		if(L)
		{
			tmx=max(tmx,L->tmx);
			tmx=max(tmx,L->rmx+v);
		}
		if(R)
		{
			tmx=max(tmx,R->tmx);
			tmx=max(tmx,R->lmx+v);
		}
		if(L&&R)
		{
			tmx=max(tmx,L->rmx+v+R->lmx);
		}
	}
}*root=NULL;
inline int size(Treap *x)
{
	return x?x->sz:0;
}
Treap* merge(Treap *a,Treap *b)
{
	if(!a||!b)return a?a:b;
	if(a->pri>b->pri)
	{
		a->down();
		a->R=merge(a->R,b);
		a->up();
		return a;
	}
	else
	{
		b->down();
		b->L=merge(a,b->L);
		b->up();
		return b;
	}
}
void spilt(Treap *tr,Treap *&a,Treap *&b,int k)
{
	if(k==0)a=NULL,b=tr;
	else if(k==size(tr))a=tr,b=NULL;
	else
	{
		tr->down();
		if(size(tr->L)>=k)
		{
			b=tr;
			spilt(tr->L,a,b->L,k);
			b->up();
		}
		else
		{
			a=tr;
			spilt(tr->R,a->R,b,k-size(tr->L)-1);
			a->up();
		}
	}
}
Treap* INS(int x)
{
	if(x==0)return NULL;
	if(x==1)return new Treap(getint());
	int mid=x>>1;
	Treap *a=INS(mid),*b=INS(x-mid);
	return a=merge(a,b);
}
inline void Insert(int pos,int k)
{
	Treap *a,*b;
	spilt(root,a,b,pos);
	root=merge(a,merge(INS(k),b));
}
inline void Delete(int pos,int k)
{
	Treap *a,*b,*c,*d;
	spilt(root,a,b,pos-1);
	spilt(b,c,d,k);
	root=merge(a,d);
}
inline void Change(int pos,int k,int l)
{
	Treap *a,*b,*c,*d;
	spilt(root,a,b,pos-1);
	spilt(b,c,d,k);
	c->cover=1;
	c->v=l;
	c->rev=0;
	c->sum=l*size(c);
	if(l>=0)c->tmx=c->rmx=c->lmx=c->sum;
	else c->tmx=c->rmx=c->lmx=l;
	root=merge(a,merge(c,d));
}
inline void Reverse(int pos,int k)
{
	Treap *a,*b,*c,*d;
	spilt(root,a,b,pos-1);
	spilt(b,c,d,k);
	c->rev^=1;
	swap(c->lmx,c->rmx);
	root=merge(a,merge(c,d));
}
inline int Getsum(int pos,int k)
{
	if(!k)return 0;
	Treap *a,*b,*c,*d;
	spilt(root,a,b,pos-1);
	spilt(b,c,d,k);
	int res=c->sum;
	root=merge(a,merge(c,d));
	return res;
}
inline int Getmax()
{
	return root?root->tmx:0;
}
void print(Treap *x)
{
	x->up();
	x->down();
	if(x->L)print(x->L);
	printf("treap %d\n",x->v);
	if(x->R)print(x->R);
}

#endif
