#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
deque<int>dq[110];
bool vis[110];
int maxdis=-1;
int maxend;
int dis[110][110];
int N;
void push(int a,int b)
{
	dq[a].push_back(b);
	//dq[b].push_back(a);
}
int lengh(int s,int t)
{
	if(dis[s][t]!=-1)return dis[s][t];
	int maxn=-1;
	int size=dq[s].size();
	for(int i=0;i<size;i++)
	{
		maxn=max(maxn,lengh(dq[s][i],t)+1);
	}
	return dis[s][t]=maxn;
}
int main()
{
	int s;
	int num=0;
	while(~scanf("%d",&N))
	{
		if(N==0)break;
		for(int i=0;i<110;i++)
		{
			dq[i].clear();
		}
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				dis[i][j]=-1;
			}
			dis[i][i]=0;
		}
		maxdis=-1;
		scanf("%d",&s);
		int f,t;
		while(scanf("%d %d",&f,&t))
		{
			if(f==0&&t==0)break;
			push(f,t);
		}
		for(int i=1;i<=N;i++)
		{
			if(maxdis<lengh(s,i))
			{
				maxdis=lengh(s,i);
				maxend=i;
			}
		}
		printf("Case %d: ",++num);
		printf("The longest path from %d has length %d, finishing at %d.\n\n",s,maxdis,maxend);
	}
}
