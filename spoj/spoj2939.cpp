#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
#define MAXN 100010
int N,top[MAXN]={0},son[MAXN]={0},sz[MAXN]={0},fa[MAXN]={0},num[MAXN],len[MAXN]={0},dep[MAXN],pos1[MAXN];
bool col[MAXN]={false};
vector<int>vc[MAXN];
vector<int>heavy[MAXN];
struct HEAP
{
	int size,*h,*pos;
	int (*cmp)(int);
	HEAP():size(0){}
	HEAP(int (*_c)(int),int *_p):size(0),pos(_p),cmp(_c){}
	inline void enlarge(int _s)
	{
		h=new int [_s+2];
	}
	inline int first()
	{
		return cmp(h[1]);
	}
	inline void insert(int _x)
	{
		h[++size]=_x;
		pos[_x]=size;
	}
	inline void down(int _x)
	{
		for(int i=_x,j=i<<1;j<=size;i=j,j=i<<1)
		{
			if(j<=size-1&&cmp(h[j+1])<cmp(h[j]))j++;
			if(cmp(h[i])<cmp(h[j]))break;
			pos[h[i]]=j;pos[h[j]]=i;
			swap(h[i],h[j]);
		}
	}
	inline void up(int _x)
	{
		for(int i=_x,j=i>>1;j;i=j,j=i>>1)
		{
			if(cmp(h[j])<cmp(h[i]))break;
			pos[h[i]]=j;pos[h[j]]=i;
			swap(h[i],h[j]);
		}
	}
	inline void build()
	{
		for(int i=size>>1;i;i>>=1)
		{
			down(i);
		}
	}
	inline void modify(int _x)
	{
		up(_x);down(_x);
	}
}d[MAXN];
struct Stree
{
	Stree *L,*R;
	int lopt,ropt;
	Stree():L(NULL),R(NULL),lopt(INF),ropt(INF){};
}*st[MAXN];
inline int cmp1(int _x)
{
	return st[_x]->lopt+1;
}
int dfs_1(int root,int f)
{
	fa[root]=f;son[root]=0;sz[root]=1;dep[root]=dep[f]+1;
	if(root==1)fa[root]=0;
	int cnt=0;
	foreach(it,vc[root])
	{
		if(*(it)!=f)
		{
			cnt++;
			sz[root]=dfs_1(*(it),root);
			if(sz[son[root]]<sz[*(it)])son[root]=*(it);
		}
	}
	d[root].enlarge(cnt+2);
	for(int i=1;i<=2;i++)d[root].insert(MAXN-1);
	foreach(it,vc[root])
	{
		if(*(it)!=f&&*(it)!=son[root])
			d[root].insert(*(it));
	}
	return sz[root];
}
void buildtree(int root,Stree *&s,int l,int r)
{
	s=new Stree();
	if(l==r)
		s->lopt=s->ropt=d[heavy[root][l]].first();
	else
	{
		int mid=(l+r)>>1;
		buildtree(root,s->L,l,mid);
		buildtree(root,s->R,mid+1,r);
		s->lopt=min(s->L->lopt,s->R->lopt+mid+1-l);
		s->ropt=min(s->R->ropt,s->L->ropt+r-mid);
	}
}
void dfs_2(int root,int t)
{
	top[root]=t;
	len[t]++;
	if(son[root])dfs_2(son[root],t);
	foreach(it,vc[root])
	{
		if(*(it)!=fa[root]&&*(it)!=son[root])
			dfs_2(*(it),*(it));
	}
	d[root].build();
	if(root==t)
	{
		heavy[root].push_back(0);
		for(int i=root,j=1;j<=len[root];j++,i=son[i])
		{
			heavy[root].push_back(i);num[i]=j;
		}
		buildtree(root,st[root],1,len[root]);
	}
}
void modify(int root,Stree *s,int l,int r,int x)
{
	if(l==r)
	{
		if(col[heavy[root][x]])
			s->lopt=s->ropt=0;
		else
			s->lopt=s->ropt=d[heavy[root][x]].first();
	}
	else 
	{
		int mid=(l+r)>>1;
		if(x<=mid)modify(root,s->L,l,mid,x);
		else if(x>=mid+1)modify(root,s->R,mid+1,r,x);
		s->lopt=min(s->L->lopt,s->R->lopt+mid+1-l);
		s->ropt=min(s->R->ropt,s->L->ropt+r-mid);
	}
}
void update(int x)
{
	if(!x)return ;
	modify(top[x],st[top[x]],1,len[top[x]],num[x]);
	if(fa[top[x]])d[fa[top[x]]].modify(pos1[top[x]]);
	update(fa[top[x]]);
}
int QL(Stree *s,int l,int r,int ll,int rr)
{
	if(l==ll&&r==rr)return s->lopt;
	int mid=(l+r)>>1;
	if(rr<=mid)return QL(s->L,l,mid,ll,rr);
	else if(ll>=mid+1)return QL(s->R,mid+1,r,ll,rr);
	else return min(QL(s->L,l,mid,ll,mid),QL(s->R,mid+1,r,mid+1,rr)+mid+1-ll);
}
int QR(Stree *s,int l,int r,int ll,int rr)
{
	if(l==ll&&r==rr)return s->ropt;
	int mid=(l+r)>>1;
	if(rr<=mid)return QR(s->L,l,mid,ll,rr);
	else if(ll>=mid+1)return QR(s->R,mid+1,r,ll,rr);
	else return min(QR(s->R,mid+1,r,mid+1,rr),QR(s->L,l,mid,ll,mid)+rr-mid);
}
int QQ(int x)
{
	int ans=INF,tmp=0;
	while(x)
	{
		int ll=QR(st[top[x]],1,len[top[x]],1,num[x]);
		int rr=QL(st[top[x]],1,len[top[x]],num[x],len[top[x]]);
		ans=min(ans,min(ll+tmp,rr+tmp));
		tmp+=num[x];
		x=fa[top[x]];
	}
	return ans;
}
void init()
{
	dep[1]=0;
	for(int i=1;i<=N;i++)
	{
		//vc[i].clear();
		d[i]=HEAP(cmp1,pos1);
	}
	st[MAXN-1]=new Stree();
}
int main()
{
	scanf("%d",&N);
	init();
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	dfs_1(1,1);
	dfs_2(1,1);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(!a)
		{
			col[b]=!col[b];
			update(b);
		}
		else
		{
			int tmp;
			printf("%d\n",(tmp=QQ(b))==INF?-1:tmp);
		}
	}
	return 0;
}

