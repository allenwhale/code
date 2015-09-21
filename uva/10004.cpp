#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
deque<int>VC[210];
int cl[210];
bool vis[210];
int m,n;
bool tf;
int inti(int n)
{
	tf=true;
	memset(cl,0,sizeof(cl));
	int i;
	for(i=0;i<n;i++)
	{
		VC[i].clear();
	}
	return 0;
}
bool DFS(int now,int l)
{
	if(!tf)return false;
	int size=VC[now].size();
	if(l==1)cl[now]=2;
	else cl[now]=1;
	int i;
	for(i=0;i<size;i++)
	{
		int to=VC[now][i];
		if(cl[to]!=0)
		{
			if(cl[to]==cl[now])return false;
			continue;
		}
		else tf=DFS(to,cl[now]);
		if(!tf)return false;
	}
	return true;
}
int main()
{
	while(scanf("%d",&n))
	{
		if(n==0)break;
		inti(n);
		scanf("%d",&m);
		int i;
		int fr,to;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&fr,&to);
			VC[fr].push_back(to);
			VC[to].push_back(fr);
		}
		tf=DFS(0,1);
		if(tf)printf("BICOLORABLE.\n");	
		else printf("NOT BICOLORABLE.\n");
	}
    return 0;
}
