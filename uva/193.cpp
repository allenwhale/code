#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
using namespace std;
deque<int>DQ[1000];
int col[1000],fcol[1000];
bool vis[1000];
int mx=0;
int c;
bool check(int pos)
{
	int i,size=DQ[pos].size();
	for(i=0;i<size;i++)
	{
		int tmp=DQ[pos][i];
		if(vis[tmp])return false;
	}
	return true;
}
int DFS(int pos)
{
	int i;
	if(pos>mx)
	{
		mx=pos;
		for(i=0;i<pos;i++)
		{
			fcol[i]=col[i];
		}
	}
	for(i=1;i<=c;i++)
	{
		if(pos==0||(check(i)&&i>col[pos-1]))
		{
			vis[i]=true;
			col[pos]=i;
			DFS(pos+1);
			vis[i]=false;
		}
	}
}
void push(int a,int b)
{
	DQ[a].push_back(b);
	DQ[b].push_back(a);
}
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		DQ[i].clear();
	}
	memset(vis,false,sizeof(vis));
	memset(col,0,sizeof(col));
	memset(fcol,0,sizeof(fcol));
	mx=0;
}
int main()
{
	int i,j,k,N;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		int r;
		scanf("%d %d",&c,&r);
		init(c);
		for(j=1;j<=r;j++)
		{
			int f,t;
			scanf("%d %d",&f,&t);
			push(f,t);
		}
		DFS(0);
		printf("%d\n",mx);
		printf("%d",fcol[0]);
		for(j=1;j<mx;j++)
		{
			printf(" %d",fcol[j]);
		}
		printf("\n");
	}
    return 0;
}
