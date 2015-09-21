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
#define MAXN 100010
using namespace std;
struct edge
{
	int to,w;
	edge(){}
	edge(int _t,int _w):to(_t),w(_w){}
};
vector<edge>vc[MAXN];
vector<int>heavy[MAXN];
int N,numw,top[MAXN],w[MAXN],fa[MAXN],sz[MAXN],son[MAXN]
	,num[MAXN],pos0[MAXN],pos1[MAXN],len[MAXN],dist[MAXN];
bool color[MAXN];
struct Stree
{
	int lopt,ropt,opt;
	Stree *L,*R;
	Stree():lopt(-INF),ropt(-INF),opt(-INF),L(NULL),R(NULL){}
}*st[MAXN];
int cmp0(int x)
{
	return st[x]->opt;
}
int cmp1(int x)
{
	return st[x]->lopt+w[x];
}
struct HEAP
{
	int size,*h,*pos,(*cmp)(int);
	HEAP():size(0){}
	HEAP(int (*_c)(int),int *_p):size(0),pos(_p),cmp(_c){}
	void enlarge(int _s)
	{
		h=new int[_s+2];
	}
	int first()
	{		
		return cmp(h[1]);
	}
	int second()
	{
		return max(cmp(h[2]),cmp(h[3]));
	}
	void insert(int _x)
	{
		h[++size]=_x;
		pos[_x]=size;
	}
	void down(int _x)
	{
		for(int i=_x,j=i<<1;j<=size;i=j,j=i<<1)
		{
			if(j<=size-1&&cmp(h[j])<cmp(h[j+1]))j++;
			if(cmp(h[i])>cmp(h[j]))break;
			pos[h[i]]=j,pos[h[j]]=i;
			swap(h[i],h[j]);
		}
	}
	void up(int _x)
	{
		for(int i=_x,j=i>>1;j;i=j,j=i>>1)
		{
			if(cmp(h[j])>cmp(h[i]))break;
			pos[h[i]]=j,pos[h[j]]=i;
			swap(h[i],h[j]);
		}
	}
	void build()
	{
		for(int i=size>>1;i;i--)down(i);
	}
	void modify(int _x)
	{
		up(_x);down(_x);
	}
}d[MAXN];
int dfs_1(int root,int f)
{
	sz[root]=1;fa[root]=f;son[root]=0;
	if(root==1)fa[root]=0;
	int cnt=0;
	foreach(it,vc[root])
	{
		if(it->to==f)continue;
		cnt++;
		dist[it->to]=dist[root]+it->w;
		w[it->to]=it->w;
		sz[root]+=dfs_1(it->to,root);
		if(sz[son[root]]<sz[it->to])son[root]=it->to;
	}
	d[root].enlarge(cnt+2);
	for(int i=1;i<=3;i++)d[root].insert(0);
	foreach(it,vc[root])
	{
		if(it->to!=fa[root]&&it->to!=son[root])d[root].insert(it->to);
	}
	return sz[root];
}
void buildtree(int root,Stree *&s,int l,int r)
{
	s=new Stree();
	if(l==r)
	{
		s->lopt=s->ropt=max(d[heavy[root][l]].first(),0);
		s->opt=max(d[heavy[root][l]].first()+d[heavy[root][l]].second(),
				   max(d[heavy[root][l]].first(),0));
	}
	else
	{
		int mid=(l+r)>>1;
		buildtree(root,s->L,l,mid);
		buildtree(root,s->R,mid+1,r);
		s->lopt=max(s->L->lopt,s->R->lopt+dist[heavy[root][mid+1]]-dist[heavy[root][l]]);
		s->ropt=max(s->R->ropt,s->L->ropt+dist[heavy[root][r]]-dist[heavy[root][mid]]);
		s->opt=max(max(s->L->opt,s->R->opt)
				  ,s->L->ropt+s->R->lopt+dist[heavy[root][mid+1]]-dist[heavy[root][mid]]);
	}
}
void dfs_2(int root,int t)
{
	top[root]=t;
	len[t]++;
	if(son[root])dfs_2(son[root],t);
	foreach(it,vc[root])
	{
		if(it->to!=fa[root]&&it->to!=son[root])dfs_2(it->to,it->to);
	}
	d[root].build();
	if(root==t)
	{
		heavy[root].push_back(0);
		for(int i=root,j=1;j<=len[root];i=son[i],j++)
		{
			heavy[root].push_back(i);num[i]=j;
		}
		buildtree(root,st[root],1,len[root]);
	}
}
void init()
{
	dist[1]=0;sz[0]=0;w[1]=0;
	for(int i=0;i<=N;i++)vc[i].clear();
	for(int i=1;i<=N;i++)d[i]=HEAP(cmp1,pos1);
	d[0]=HEAP(cmp0,pos0);
	numw=N;
	MS(len,0);
	MS(son,0);
	MS(fa,0);
	st[0]=new Stree();
}
void modify(int root,Stree *s,int l,int r,int x)
{
	if(l==r)
	{
		if(color[heavy[root][l]])
		{
			s->lopt=s->ropt=d[heavy[root][l]].first();
			s->opt=d[heavy[root][l]].first()+d[heavy[root][l]].second();
		}
		else
		{
			s->lopt=s->ropt=max(d[heavy[root][l]].first(),0);
			s->opt=max(d[heavy[root][l]].first()+d[heavy[root][l]].second(),
					   d[heavy[root][l]].first());
		}
	}
	else
	{
		int mid=(l+r)>>1;
		if(x<=mid)modify(root,s->L,l,mid,x);
		else if(x>=mid+1)modify(root,s->R,mid+1,r,x);
		s->lopt=max(s->L->lopt,s->R->lopt+dist[heavy[root][mid+1]]-dist[heavy[root][l]]);
		s->ropt=max(s->R->ropt,s->L->ropt+dist[heavy[root][r]]-dist[heavy[root][mid]]);
		s->opt=max(max(s->L->opt,s->R->opt)
				  ,s->L->ropt+s->R->lopt+dist[heavy[root][mid+1]]-dist[heavy[root][mid]]);
	}
}
void update(int x)
{
	if(!x)return;
	modify(top[x],st[top[x]],1,len[top[x]],num[x]);
	d[0].modify(pos0[top[x]]);
	if(fa[top[x]])d[fa[top[x]]].modify(pos1[top[x]]);
	update(fa[top[x]]);
}
int main()
{
	scanf("%d",&N);
	init();
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].push_back(edge(b,c));
		vc[b].push_back(edge(a,c));
	}
	dfs_1(1,1);
	dfs_2(1,1);
	int cnt=0;
	for(int i=1;i<=N;i++)
		if(i==top[i])cnt++;
	d[0].enlarge(cnt+2);
	for(int i=1;i<=N;i++)
		if(i==top[i])d[0].insert(i);
	d[0].build();
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		getchar();
		char c;
		scanf("%c",&c);
		if(c=='A')
		{
			if(!numw)puts("They have disappeared.");
			else printf("%d\n",max(d[0].first(),0));
		}
		else if(c=='C')
		{
			int a;
			scanf("%d",&a);
			if(color[a])numw++;
			else numw--;
			color[a]=!color[a];
			update(a);
		}
	}
	return 0;
}
