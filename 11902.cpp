#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
#include <time.h>
using namespace std;
deque<int>DQ[110];
char s[110][110];
bool vis[110];
bool BFS(int d)
{
	queue<int>Q;
	memset(vis,false,sizeof(vis));
	int i;
	int size=DQ[0].size();
	vis[0]=true;
	for(i=0;i<size;i++)
	{
		int tmp=DQ[0][i];
		if(!vis[tmp]&&tmp!=d)Q.push(tmp);
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
			int t=DQ[tmp][i];
			if(!vis[t]&&t!=d)Q.push(t);
		}
	}
}
void build(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			for(j=0;j<n;j++)
			{
				s[i][j]='Y';
			}
		}
		else
		{
			BFS(i);
			for(j=0;j<n;j++)
			{
				if(vis[j])s[i][j]='N';
				else s[i][j]='Y';
			}
		}
	}
}
int main()
{
	//freopen("out.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	int N,n,i,j,k;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{

		scanf("%d",&n);
		char sss[1000];
		sss[0]=sss[2*n]='+';
		for(j=1;j<2*n;j++)
		{
			sss[j]='-';
		}
		sss[2*n+1]='\0';
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				int r;
				scanf("%d",&r);
				if(r)DQ[j].push_back(k);
			}
		}
		build(n);
		printf("Case %d:\n",i);
		for(j=0;j<n;j++)
		{
			printf("%s\n",sss);
			for(k=0;k<n;k++)
			{
				printf("|%c",s[j][k]);
			}
			printf("|\n");
		}
		printf("%s\n",sss);
	}
    return 0;
}
