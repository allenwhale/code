#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#define PB push_back
using namespace std;
vector<int>vc[1010];
int DP[2][1010][1010];
int app[1010];
int N,K;
void init()
{
	memset(DP,-1,sizeof(DP));
	for(int i=0;i<1010;i++)vc[i].clear();
}
void DFS(int x,int p,int dep)
{
	int size=vc[x].size();
	if(x==0)DP[0][0][1]=app[0];
	else
	{
		for(int i=dep;i<=K;i++)
		{
			if(DP[0][p][i-1]==-1)continue;
			DP[0][x][i]=DP[0][p][i-1]+app[x];
		}
	}
	for(int j=0;j<size;j++)
	{
		int to=vc[x][j];
		if(to==p)continue;
		DFS(to,x,dep+1);
		for(int i=dep;i<=K;i++)
		{
			DP[0][x][i]=max(DP[0][x][i],DP[0][to][i-1]);
		}
		for(int i=dep;i<=K;i++)
		{
			DP[1][x][i]=max(DP[1][x][i],DP[0][to][i]);
		}
		for(int i=dep;i<=K;i++)
		{
			DP[1][x][i]=max(DP[1][x][i],DP[1][to][i]);
		}
	}
}
int main()
{
	while(~scanf("%d %d",&N,&K))
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d",&app[i]);
		}
		for(int i=0;i<N-1;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			vc[a].PB(b),vc[b].PB(a);
		}
		DFS(0,-1,1);
		int ans=max(DP[0][0][K],DP[1][0][K]);
		/*
		for(int i=0;i<N;i++)
		{
			for(int j=1;j<=K;j++)
			{
				printf("num %d step %d here %d other %d\n",i,j,DP[0][i][j],DP[1][i][j]);
			}
		}
		*/
		printf("%d\n",ans);
	}
	return 0;
}

