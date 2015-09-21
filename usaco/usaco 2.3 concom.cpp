/*
ID: allenwh1
PROG: concom
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define ms0(a) memset(a,0,sizeof(a))
#define msf(a) memset(a,false,sizeof(a)) 
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
int stock[110][110];
bool own[110];
int con[110];
bool vis[110];
int N,maxn=0;
void DFS(int x)
{
	if(vis[x])return;
	vis[x]=true;
	for(int i=1;i<=maxn;i++)
	{
		con[i]+=stock[x][i];
		if(con[i]>50)
		{
			
			own[i]=true;
			DFS(i);
		}
	}
}
int main()
{
	fin("concom.in");
	fout("concom.out");
	scanf("%d",&N);
	ms0(stock);
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		stock[a][b]=c;
		maxn=max(max(a,b),maxn);
	}
	for(int i=1;i<=maxn;i++)
	{
		ms0(con);
		msf(own);
		msf(vis);
		DFS(i);
		for(int j=1;j<=maxn;j++)
		{
			if(own[j]&&i!=j)
			{
				printf("%d %d\n",i,j);
			}
		}
	}
//	while(1);
    return 0;
}
