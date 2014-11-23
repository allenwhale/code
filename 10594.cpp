#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
using namespace std;
typedef long long ll;
#define INF 99999999
int s=1,tt;
struct edge
{
	int f,t,r,w;
}edge[22000];
deque<int>dq[110];
int en=2;
int N,M;
int ec,ac;
int d[110];
int p[110];
void add(int f,int t,int w)
{
	edge[en].f=f,edge[en].t=t,edge[en].w=w,dq[f].push_back(en),en++;
	edge[en].f=t,edge[en].t=f,edge[en].w=-w,dq[t].push_back(en),en++;
	edge[en].f=t,edge[en].t=f,edge[en].w=w,dq[t].push_back(en),en++;
	edge[en].f=f,edge[en].t=t,edge[en].w=-w,dq[f].push_back(en),en++;
}
ll mincost()
{
	ll t=0;
	int f=ac;
	int i,size;
	while(true)
	{
		queue<int>q;
		memset(p,0,sizeof(p));
		fill(d,d+109,INF);
		d[s]=0;
		p[s]=-1;
		q.push(s);
		while(!q.empty())
		{
			int t=q.front();
			q.pop();
			size=dq[t].size();
			for(i=0;i<size;i++)
			{
				int n=dq[t][i];
				if(edge[n].r>0&&d[edge[n].f]+edge[n].w<d[edge[n].t]&&d[edge[n].t]!=0)
				{
					d[edge[n].t]=d[edge[n].f]+edge[n].w;
					p[edge[n].t]=n;
					q.push(edge[n].t);
				}
			}
		}
		if(d[tt]==INF)break;
		int df=INF;
		ll dc;
		for(i=p[tt];i!=-1;i=p[edge[i].f])
		{
			df=min(df,edge[i].r);
		}
		if(df>f)df=f;
		for(i=p[tt];i!=-1;i=p[edge[i].f])
		{
			edge[i].r-=df,edge[i^1].r+=df;
		}
		dc=(ll)df*(ll)d[tt];
		f-=df;
		t+=dc;
		if(f==0)break;
	}
	return f==0?t:-1;
}
void init(int n)
{
	for(int i=1;i<=n;i++)dq[i].clear();
	en=2;
}
int main()
{
	while(~scanf("%d %d",&N,&M))
	{
		init(N);
		tt=N;
		for(int i=0;i<M;i++)
		{
			int f,t,w;
			scanf("%d %d %d",&f,&t,&w);
			add(f,t,w);
		}
		scanf("%d %d",&ac,&ec);
		for(int i=2;i<en;i++)
		{
			if(edge[i].w<0)edge[i].r=0;
			else edge[i].r=ec;
		}
		ll ans=mincost();
		if(ans==-1)
		{
			printf("Impossible.\n");
		}
		else
		{
			printf("%lld\n",ans);
		}
	}
    return 0;
}
