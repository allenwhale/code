#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
int C,R;
bool vis[110];
struct r
{
	int t,d;
	r(int tt,int td)
	{
		t=tt,d=td;
	}
	bool operator<(const r &n)const
	{
		return n.d>d;
	}
};

deque<r>dq[110];
void add(int a,int b,int d)
{
	dq[a].push_back(r(b,d));
	dq[b].push_back(r(a,d));
	return;
}
int find(int s,int t)
{
	memset(vis,false,sizeof(vis));
	priority_queue<r>pq;
	vis[s]=true;
	int size=dq[s].size();
	for(int i=0;i<size;i++)
	{
		pq.push(dq[s][i]);
	}
	int minn=9999999;
	while(!pq.empty())
	{
		r tt=pq.top();
		pq.pop();
		if(vis[tt.t])continue;
		vis[tt.t]=true;
		size=dq[tt.t].size();
		minn=min(minn,tt.d);
		if(tt.t==t)return minn;
		for(int i=0;i<size;i++)
		{
			r tmp=dq[tt.t][i];
			if(vis[tmp.t])continue;
			pq.push(tmp);
		}
	}
	return -1;
}

int main()
{
	int num=0;
	while(scanf("%d %d",&C,&R))
	{
		if(C==0&&R==0)break;
		for(int i=1;i<=C;i++)
		{
			dq[i].clear();
		}
		for(int i=0;i<R;i++)
		{
			int a,b,d;
			scanf("%d %d %d",&a,&b,&d);
			add(a,b,d);
		}
		int f,t,p;
		scanf("%d %d %d",&f,&t,&p);
		int ans;
		int mx=find(f,t)-1;
		if(p%mx==0)ans=p/mx;
		else ans=p/mx+1;
		printf("Scenario #%d\n",++num);
		printf("Minimum Number of Trips = %d\n\n",ans);
	}
	return 0;
}
