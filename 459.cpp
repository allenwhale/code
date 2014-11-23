#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
using namespace std;
deque<int>DQ[10010];
bool vis[10010];
void push(int a,int b)
{
	DQ[a].push_back(b);
	DQ[b].push_back(a);
}
void BFS(int x)
{
	queue<int>Q;
	int i;
	int size=DQ[x].size();
	vis[x]=true;
	for(i=0;i<size;i++)
	{
		if(!vis[DQ[x][i]])Q.push(DQ[x][i]);
	}
	
	while(!Q.empty())
	{
		int tmp=Q.front();
		Q.pop();
		if(vis[tmp])continue;
		vis[tmp]=true;
		size=DQ[tmp].size();
		for(i=0;i<size;i++)
		{
			if(!vis[DQ[tmp][i]])Q.push(DQ[tmp][i]);
		}
	}
}
int count(int n)
{
	memset(vis,false,sizeof(vis));
	int i;
	int c=0;
	for(i=0;i<=n;i++)
	{
		//printf("%d\n",i);
		if(!vis[i])BFS(i),c++;
	}
	return c;
}
void init()
{
	int i;
	for(i=0;i<26;i++)
	{
		DQ[i].clear();
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	getchar();
	int i;
	for(i=1;i<=N;i++)
	{
		char mx;
		scanf("%c",&mx);
		//printf("%c",mx);
		getchar();
		int n=mx-'A';
		init();
		char s[10];
		while(gets(s)!=NULL)
		{
			if(strlen(s)==0)break;
			int f=s[0]-'A',t=s[1]-'A';
			push(t,f);
		}
		//printf("sss");
		int ans=count(n);
		if(i>1)printf("\n");
		printf("%d\n",ans);
	}
    return 0;
}
