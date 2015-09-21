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
int N,fa[MAXN],tid[MAXN],id[MAXN],dep[MAXN],top[MAXN],sz[MAXN],son[MAXN],t;
vector<int>vc[MAXN];
int dfs_1(int root,int f)
{
	dep[root]=dep[f]+1;sz[root]=1;fa[root]=f;son[root]=0;
	foreach(it,vc[root])
	{
		if(*(it)==f)continue;
		sz[root]+=dfs_1(*(it),root);
		if(sz[son[root]]<sz[*(it)])son[root]=*(it);
	}
	return sz[root];
}
void dfs_2(int root,int f)
{
	top[root]=f;id[t]=root;tid[root]=t++;
	if(son[root])dfs_2(son[root],f);
	foreach(it,vc[root])
	{
		if(*(it)==fa[root]||*(it)==son[root])continue;
		dfs_2(*(it),*(it));
	}
}
struct Segtree
{
	int L,R,c,pos;
	inline int mid()
	{
		return (L+R)>>1;
	}
}St[MAXN<<2];
void buildtree(int l,int r,int idx)
{
	St[idx].L=l,St[idx].R=r,St[idx].c=St[idx].pos=0;
	if(l==r)return;
	int mid=St[idx].mid();
	buildtree(l,mid,idx<<1);
	buildtree(mid+1,r,(idx<<1)|1);
}
void modify(int x,int idx)
{
	if(St[idx].L==St[idx].R)
	{
		St[idx].c^=1;
		if(St[idx].c)St[idx].pos=id[St[idx].L];
		else St[idx].pos=0;
		return ;
	}
	int mid=St[idx].mid();
	if(x<=mid)modify(x,idx<<1);
	else modify(x,(idx<<1)|1);
	if(St[idx<<1].c)
	{
		St[idx].c=St[idx<<1].c;
		St[idx].pos=St[idx<<1].pos;
	}
	else
	{
		St[idx].c=St[(idx<<1)|1].c;
		St[idx].pos=St[(idx<<1)|1].pos;
	}
}
int ask(int l,int r,int idx)
{
	//printf("  %d %d %d %d %d %d %d\n",l,r,St[idx].L,St[idx].R,St[idx].c,St[idx].pos,idx);
	if(St[idx].L==l&&St[idx].R==r)
	{
		return St[idx].pos;
	}
	int mid=St[idx].mid();
	if(r<=mid)return ask(l,r,idx<<1);
	else if(l>=mid+1)return ask(l,r,(idx<<1)|1);
	else 
	{
		int tmp=ask(l,mid,idx<<1);
		if(tmp)return tmp;
		return ask(mid+1,r,(idx<<1)|1);
	}
}
int query(int x)
{
	int y=1;
	int ans=-1;
	while(top[x]!=top[y])
	{
		//printf("  %d\n",x);
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		int tmp=ask(tid[top[x]],tid[x],1);
		if(tmp)ans=tmp;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	int tmp=ask(tid[x],tid[y],1);
	if(tmp)ans=tmp;
	return ans;
}
void init()
{
	for(int i=0;i<=N;i++)vc[i].clear();
	dep[1]=0;son[0]=0;sz[0]=0;t=1;
}
int main()
{
	int Q;
	scanf("%d %d",&N,&Q);
	init();
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	dfs_1(1,1);
	
//puts("dfs1");
	dfs_2(1,1);
	//for(int i=1;i<=N;i++)
///		printf("%d %d\n",i,tid[i]);
//	puts("dfs2");
	buildtree(1,N,1);
//	puts("build");
	while(Q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==0)modify(tid[b],1);
		else printf("%d\n",query(b));
	}
	return 0;
}

