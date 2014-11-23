#include <stdio.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
bool vis[10010];
int d[10010];
int mn=0;
int diameter=0;
struct state
{
	int to,ct;
	state(int tt,int tc)
	{
		to=tt;
		ct=tc;
	}
};
deque<state>DQ[10010];
void push(int f,int t,int c)
{
	DQ[f].push_back(state(t,c));
	DQ[t].push_back(state(f,c));
}
int DFS(int x,int px)
{
	int h1=0,h2=0;
	int size=DQ[x].size();
	int i;
	for(i=0;i<size;i++)
	{
		if(DQ[x][i].to==px)continue;
		int h=DFS(DQ[x][i].to,x)+DQ[x][i].ct;
		if(h>h1)h2=h1,h1=h;
		else if(h>h2)h2=h;
	}
	diameter=max(diameter,h1+h2);
	return h1; 
}
int main()
{
	int fr,to,ct,i,j,size;
	char s[30];
	bool tf=true;
	while(gets(s)!=NULL&&tf)
	{
		diameter=0;
		for(i=1;i<10010;i++)
		{
			DQ[i].clear();
		}
		if(s[0]=='\0')
		{
			printf("0\n");
			continue;
		}
		mn=0; 
		sscanf(s,"%d %d %d",&fr,&to,&ct);
		push(fr,to,ct);
		mn=max(mn,fr);
		mn=max(mn,to);
		while(1)
		{
			if(gets(s)==NULL)
			{
				tf=false;
				break;
			} 
			if(s[0]=='\0')break;
			sscanf(s,"%d %d %d",&fr,&to,&ct);
			mn=max(mn,fr);
			mn=max(mn,to);
			push(fr,to,ct);
		}
		DFS(1,1);
		printf("%d\n",diameter);
		if(!tf)break;
	}
    return 0;
}
