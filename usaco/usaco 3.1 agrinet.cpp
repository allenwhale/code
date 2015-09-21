/*
ID: allenwh1
PROG: agrinet
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
int d[110][110];
bool vis[110];
struct state
{
	int t,d;
	state(int tt,int td)
	{
		t=tt,d=td;
	}
	bool operator<(const state &n)const
	{
		return d>n.d;
	}
};
priority_queue<state>pq;
int main()
{
	fin("agrinet.in");
	fout("agrinet.out");
	memset(vis,false,sizeof(vis));
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&d[i][j]);
		}
	}
	int tot=0;
	int n=0;
	for(int i=1;i<N;i++)
	{
		pq.push(state(i,d[0][i]));
	}
	vis[0]=true;
	while(n<N-1)
	{
		state tt=pq.top();
		pq.pop();
		if(vis[tt.t])continue;
		n++;
		vis[tt.t]=true;
		tot+=tt.d;
		for(int i=0;i<N;i++)
		{
			if(i==tt.t||vis[i])continue;
			pq.push(state(i,d[tt.t][i]));
		}
	}
	printf("%d\n",tot);
//	while(1);
    return 0;
}
