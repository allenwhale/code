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
#define INF 0x3fffffff
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
#define MAXN 210010
using namespace std;
struct edge
{
	int to,c;
	edge(int _t,int _c):to(_t),c(_c){}
};
struct EDGE
{
	int a,b,c;
}E[MAXN];
vector<edge>vc[MAXN];
int dep[MAXN],top[MAXN],ti[MAXN],son[MAXN],fa[MAXN],sz[MAXN];
int N,idx=1;
int dfs_1(int root,int f)
{
	dep[root]=dep[f]+1,sz[root]=1,son[root]=0,fa[root]=f;
	foreach(it,vc[root])
	{
		if(it->to==f)continue;
		sz[root]+=dfs_1(it->to,root);
		if(sz[son[root]]<sz[it->to])son[root]=it->to;
	}
	return sz[root];
}
void dfs_2(int root,int f)
{
	//printf("  %d\n",root);
	//system("pause");
	ti[root]=idx++,top[root]=f;
	if(son[root]!=0)dfs_2(son[root],top[root]);
	foreach(it,vc[root])
	{
		if(it->to==fa[root]||it->to==son[root])continue;
		dfs_2(it->to,it->to);
	}
}
struct Segtree
{
	int L,R,val;
}Stree[MAXN<<2];
void buildtree(int l,int r,int id)
{
	Stree[id].L=l,Stree[id].R=r,Stree[id].val=-INF;
	if(l==r)return;
	int mid=(l+r)>>1;
	buildtree(l,mid,id*2);
	buildtree(mid+1,r,id*2+1);
	return;
}
void update(int x,int w,int id)
{
	if(Stree[id].L==Stree[id].R)
		Stree[id].val=w;
	else
	{
		int mid=(Stree[id].L+Stree[id].R)>>1;
		if(x<=mid)update(x,w,id*2);
		else update(x,w,id*2+1);
		Stree[id].val=max(Stree[id*2].val,Stree[id*2+1].val);
	}
	return;
}
int query(int l,int r,int id)
{
	//printf("  %d %d %d %d %d\n",l,r,Stree[id].L,Stree[id].R,id);
	if(Stree[id].L==l&&Stree[id].R==r)return Stree[id].val;
	int mid=(Stree[id].L+Stree[id].R)>>1;
	if(r<=mid)return query(l,r,id*2);
	else if(l>mid)return query(l,r,id*2+1);
	else return max(query(l,mid,id*2),query(mid+1,r,id*2+1));
}
int lca(int x,int y)
{
	int ans=-INF;
	while(top[x]!=top[y])
	{
		
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,query(ti[top[x]],ti[x],1));
		//printf("  %d %d %d %d %d\n",x,y,top[x],top[y],ans);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x==y)return ans;
	else return ans=max(ans,query(ti[x]+1,ti[y],1));
}
void init()
{
	for(int i=0;i<=N;i++)vc[i].clear();
	dep[1]=0,sz[0]=0;idx=1;
	
}
int main()
{
	int _T;
	scanf("%d",&_T);
	while(_T--)
	{
		scanf("%d",&N);
		init();
		for(int i=1;i<=N-1;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			E[i].a=a,E[i].b=b,E[i].c=c;
			vc[a].push_back(edge(b,c));
			vc[b].push_back(edge(a,c));
		}
		//puts("input");	
		dfs_1(1,1);
		//puts("dfs_1");
		dfs_2(1,1);
		//puts("dfs_2");
		buildtree(2,N,1);
	//	puts("build");
		for(int i=1;i<=N-1;i++)
		{
			if(dep[E[i].a]<dep[E[i].b])swap(E[i].a,E[i].b);
			update(ti[E[i].a],E[i].c,1);
		}
		char s[1000];
		while(true)
		{
			scanf("%s",s);
			if(s[0]=='D')break;
			//printf("  %s\n",s);
			int a,b;
			scanf("%d %d",&a,&b);
			if(s[0]=='Q')
			{
				//printf(" x=%d y=%d\n",a,b);
				printf("%d\n",lca(a,b));
			}
			else if(s[0]=='C')
			{
				update(ti[E[a].a],b,1);
			}
		}
		//puts("");
	}
	return 0;
}

