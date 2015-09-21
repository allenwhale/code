#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
deque<int>DQ[10010];
int dis[10010],low[10010];
bool vis[10010][10010];
int t=0;
void push(int f,int t)
{
	DQ[f].push_back(t);
	DQ[t].push_back(f);
}
void initp()
{
	memset(dis,0,sizeof(dis));
	memset(low,0,sizeof(low));
	memset(vis,false,sizeof(vis));
	t=0;
}
void DFS(int x,int px)
{
	dis[x]=low[x]=++t;
	int i;
	int size=DQ[x].size();
	for(i=0;i<size;i++)
	{
		int tmp=DQ[x][i];
		if(tmp==px)continue;
		if(dis[tmp])low[x]=min(low[x],dis[tmp]);
		else 
		{
			DFS(tmp,x);
			low[x]=min(low[x],low[tmp]);
		}
	}
}
void prr(int x,int px)
{
	int i;
	int size=DQ[x].size();
	for(i=0;i<size;i++)
	{
		int tmp=DQ[x][i];
		if(tmp==px||vis[x][tmp])continue;
		vis[x][tmp]=vis[tmp][x]=true;
		printf("%d %d\n",x,tmp);
		if(dis[x]<low[tmp])printf("%d %d\n",tmp,x);
		prr(tmp,x);
	}
}
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		DQ[i].clear();
	}
	memset(dis,0,sizeof(dis));
	memset(low,0,sizeof(low));
	memset(vis,false,sizeof(vis));
	t=0;
}
int main()
{
	int n,r,i,j;
	int tt=1;
	while(scanf("%d %d",&n,&r))
	{
		
		if(n==0&&r==0)break;
		init(n);
		for(i=1;i<=r;i++)
		{
			int f,t;
			scanf("%d %d",&f,&t);
			push(t,f);
		}
		printf("%d\n\n",tt);
		tt++;
		DFS(1,1);
		prr(1,1);
		printf("#\n");
	}
    return 0;
}
