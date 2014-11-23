#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
deque<int>DQ[10010];
int dis[10010],low[10010];
bool vis[10010];
int t=0;
bool DFS(int x,int px)
{
	dis[x]=low[x]=++t;
	int c=0;
	int size=DQ[x].size();
	int i;
	for(i=0;i<size;i++)
	{
		int tmp=DQ[x][i];
		if(!dis[tmp])
		{
			if(!DFS(tmp,x))return false;
			if(dis[x]>low[tmp])if(++c>1)return false;
			low[x]=min(low[x],low[tmp]);
		}
		else 
		{
			if(vis[tmp])return false;
			if(dis[tmp]<low[x])if(++c>1)return false;
			low[x]=min(low[x],dis[tmp]);
		}
	}
	vis[x]=true;
	return x==px?true:c==1;
}
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
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
	int N,i,j,n,m;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		init(N);
		scanf("%d %d",&n,&m);
		//if(n==0||m==0)
//		{
//			printf("NO\n");
//			continue;
//		}
		for(j=1;j<=m;j++)
		{
			int f,t;
			scanf("%d %d",&f,&t);
			DQ[f].push_back(t);
		}
		if(DFS(0,0)&&t==n)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
