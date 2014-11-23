#include <iostream>
#include <deque>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int mp[110][110];
bool vis[110];
int C,S,Q;
struct r
{
	int t,d;
	r(int tt,int td)
	{
		t=tt,d=td;
	}
	bool operator<(const r &n)const
	{
		return n.d<d;
	}
};
deque<r>dq[110];
int find(int s,int t)
{
	memset(vis,false,sizeof(vis));
	priority_queue<r>pq;
	int maxn=-1;
	int size=dq[s].size();
	for(int i=0;i<size;i++)
	{
		pq.push(dq[s][i]);
	}
	vis[s]=true;
	while(!pq.empty())
	{
		r tmp=pq.top();
		pq.pop();
		if(vis[tmp.t])continue;
		vis[tmp.t]=true;
		maxn=max(maxn,tmp.d);
		if(tmp.t==t)return maxn;
		size=dq[tmp.t].size();
		for(int i=0;i<size;i++)
		{
			r tt=dq[tmp.t][i];
			if(vis[tt.t])continue;
			pq.push(tt);
		}
	}
	return -1;
}
void add(int a,int b,int d)
{
	dq[a].push_back(r(b,d));
	dq[b].push_back(r(a,d));
}
int main()
{
	int num=0;
	while(scanf("%d %d %d",&C,&S,&Q))
	{
		if(C==0&&S==0&&Q==0)break;
		memset(mp,1,sizeof(mp));
		for(int i=1;i<=C;i++)
		{
			dq[i].clear();
		}
		for(int i=0;i<S;i++)
		{
			int a,b,d;
			scanf("%d %d %d",&a,&b,&d);
			add(a,b,d);
		}
		if(num)printf("\n");
		printf("Case #%d\n",++num);
		for(int i=0;i<Q;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			int d=find(a,b);
			if(d==-1)printf("no path\n");
			else printf("%d\n",d);
		}
	}
}
