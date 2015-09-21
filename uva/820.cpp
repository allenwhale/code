#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
using namespace std;
deque<int>dq[110];
int e[110];
int p[110];
bool vis[110];
int N,s,t,c;
int en=0;
struct edge
{
	int f,t,r,num;
}edge[4100];
void push(int f,int t,int c)
{
	edge[en].f=f,edge[en].t=t,edge[en].r=c,dq[f].push_back(en),en++;
	edge[en].f=t,edge[en].t=f,edge[en].r=0,dq[t].push_back(en),en++;
	edge[en].f=t,edge[en].t=f,edge[en].r=c,dq[t].push_back(en),en++;
	edge[en].f=f,edge[en].t=t,edge[en].r=0,dq[f].push_back(en),en++;
}
int maxflow()
{
	int f=0;
	int i,size;
	while(true)
	{
		queue<int>q;
		memset(p,0,sizeof(p));
		memset(vis,false,sizeof(vis));
		q.push(s);
		vis[s]=true;
		p[s]=-1;
		while(!q.empty()&&!p[t])
		{
			int t=q.front();
			q.pop();
			size=dq[t].size();
			for(i=0;i<size;i++)
			{
				int n=dq[t][i];
				if(edge[n].r && !vis[edge[n].t])
				{
					vis[edge[n].t]=true;
					p[edge[n].t]=n;
					q.push(edge[n].t);
				}
			}
		}
		if(!p[t])break;
		int df=1e9;
		for(i=p[t];i!=-1;i=p[edge[i].f])
		{
			df=min(df,edge[i].r);
		}
		for(i=p[t];i!=-1;i=p[edge[i].f])
		{
			edge[i].r-=df,edge[i^1].r+=df;
		}
		f+=df;
	}
	return f;
}
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dq[i].clear();	
	}
	en=2;
	memset(e,0,sizeof(e));
}
int main()
{
    int n=0;
	while(scanf("%d",&N))
	{
		
		if(N==0)break;
		init(N);
		n++;
		scanf("%d %d %d",&s,&t,&c);
		for(int i=0;i<c;i++)
		{
			int a,b,ab;
			scanf("%d %d %d",&a,&b,&ab);
			push(a,b,ab);
		}
		int ans=maxflow();
		printf("Network %d\n",n);
		printf("The bandwidth is %d.\n",ans);
	}
    return 0;
}
