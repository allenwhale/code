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
#define MAXN 10010
using namespace std;
struct edge
{
	int to,w;
	edge(){}
	edge(int _t,int _w):to(_t),w(_w){}
};
vector<edge>vc[MAXN];
int N,fa[MAXN],dep[MAXN],dist[MAXN],p[MAXN][22],tin[MAXN],tout[MAXN],t;
inline int lg(int x)
{
	int i=0;
	while((1<<i)<=x)i++;
	return i-1;
}
void dfs(int root,int f)
{
	//printf("root=%d father=%d\n",root,f);
	tin[root]=t++;dep[root]=dep[f]+1;fa[root]=f;
	p[root][0]=fa[root];
	for(int i=1,j=lg(N);i<=j;i++)
	{
		p[root][i]=p[p[root][i-1]][i-1];
	}
	foreach(it,vc[root])
	{
		if(it->to==f)continue;	
		dist[it->to]=dist[root]+it->w;
		dfs(it->to,root);
	}
	tout[root]=t++;
}
inline bool acestor(int x,int y)
{
	return tin[x]<=tin[y]&&tout[x]>=tout[y];
}
int lca(int a,int b)
{
	if(acestor(a,b))return a;
	if(acestor(b,a))return b;
	//puts("lca");
	for(int i=lg(N);i>=0;i--)
	{
		//printf("  %d %d %d\n",a,i,p[a][i]);
		if(!acestor(p[a][i],b))a=p[a][i];
	}
	return p[a][0];
}
int kth(int a,int k)
{
	for(int i=0,j=lg(N);i<=j;i++)
	{
		if((k>>i)&1)a=p[a][i];
	}
	return a;
}
int query(int a,int b,int k)
{
	int LCA=lca(a,b);
	//printf(" %d %d lca=%d\n",a,b,LCA);
	int da=dep[a],db=dep[b],dl=dep[LCA];
	if(da-k+1==dl)return LCA;
	else if(da-dl+1>k)
	{
		return kth(a,k-1);		
	}
	else if(da-dl+1<k)
	{
		return kth(b,da+db-2*dl+1-k+1-1);//da+db-2*dl+1-k+1
	}
	return -1;
}
int _dist(int a,int b)
{
	int LCA=lca(a,b);
	return dist[a]+dist[b]-2*dist[LCA];
}
void init()
{
	for(int i=0;i<=N;i++)vc[i].clear();
	for(int i=0,tmp=lg(N);i<=N;i++)
	{
		for(int j=0;j<=tmp;j++)p[i][j]=1;
	}
	dep[1]=-1;t=0;dist[1]=0;
}
int main()
{
	int _T;
	scanf("%d",&_T);
	while(_T--)
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
		dfs(1,1);
		char s[10];
		while(~scanf("%s",s)&&strcmp(s,"DONE")!=0)
		{
			int a,b,c;
			
			if(s[0]=='D')
			{
				scanf("%d %d",&a,&b);
				printf("%d\n",_dist(a,b));
			}
			else if(s[0]=='K')
			{
				scanf("%d %d %d",&a,&b,&c);
				printf("%d\n",query(a,b,c));
			}
		}
	}
	return 0;
}

