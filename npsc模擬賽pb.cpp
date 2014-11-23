#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
struct Edge
{
	int to;
	ll d;
	Edge(int _t,ll _d)
	{
		to=_t,d=_d;
	}
	Edge(){}
};
struct Cost
{
	int v;
	ll c;
	Cost(int _v,ll _c)
	{
		v=_v,c=_c;
	}
	Cost(){}
};
vector<Edge>vc[51000];
vector<int>ans;
int act[51000];
int child[51000];
bool vis[51000];
ll minc;
int allact;
int N,M;
void init(int n)
{
	for(int i=0;i<=n;i++)vc[i].clear();
	memset(act,0,sizeof(act[0])*(N+10));
	memset(child,0,sizeof(child[0])*(N+10));
	memset(vis,0,sizeof(vis[0])*(N+10));
	minc=0;
	allact=0;
	ans.clear();
}
int DFS(int x)
{
	//vis[x]=true;
	int c=act[x];
	//printf("act %d %d\n",x,c);
	int size=vc[x].size();
	for(int i=0;i<size;i++)
	{
		Edge v=vc[x][i];
		if(vis[v.to])continue;
		vis[v.to]=true;
		//printf("%d to %d\n",x,v.to);
		int tmpc=DFS(v.to);
		c+=tmpc;
		minc+=(ll)2*v.d*tmpc;
	}
	//printf("act %d %d\n",x,child[x]=c);
	return child[x]=c;
}
void check(Cost n)
{
	//printf("  %d %d\n",n.v,n.c);
	if(n.c==minc)
	{
		ans.push_back(n.v);
	}
	else if(n.c<minc)
	{
		ans.clear();
		minc=n.c;
		ans.push_back(n.v);
	}
	else ;
}
void BFS(int s)
{
	memset(vis,false,sizeof(vis));
	queue<Cost>q;
	q.push(Cost(s,minc));
	while(!q.empty())
	{
		Cost tmp=q.front();
		q.pop();
		check(tmp);
		vis[tmp.v]=true;
		int size=vc[tmp.v].size();
		for(int i=0;i<size;i++)
		{			
			Edge t=vc[tmp.v][i];
			if(vis[t.to])continue;
			//vis[t.to]=true;
			ll tmpc=(ll)tmp.c+2*t.d*(allact-child[t.to])-2*t.d*child[t.to];
			q.push(Cost(t.to,tmpc));
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		init(N);
		for(int i=0;i<N-1;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			//printf("%d %d %d\n",a,b,c);
			vc[a].push_back(Edge(b,c));
			vc[b].push_back(Edge(a,c));
		}

		scanf("%d",&M);
		for(int i=0;i<M;i++)
		{
			int a,f;
			scanf("%d %d",&a,&f);
			act[a]=f;
			allact+=f;
		}
		vis[1]=true;
		DFS(1);
		BFS(1);
		printf("%lld\n",minc);
		int size=ans.size();
		sort(ans.begin(),ans.end());
		for(int i=0;i<size;i++)	
		{
			printf("%d%c",ans[i],i==size-1?'\n':' ');
		}
	}
	return 0;
}

