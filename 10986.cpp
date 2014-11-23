#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int d[20010];
int k=1;
bool vis[20010];
struct state
{
	int fr;
	int to;
	int ct;
	state(int tfr,int tto,int tct)
	{
		fr=tfr;
		to=tto;
		ct=tct;
	}
	bool operator < (const state &n) const
	{
		if(ct<n.ct)return false;
		return true;
	}
};
int main()
{
	int N;
	scanf("%d",&N);
	int i,sv,cb,st,ed;
	for(k=1;k<=N;k++)
	{
		memset(d,0,sizeof(d));
		memset(vis,false,sizeof(vis));
		scanf("%d %d %d %d",&sv,&cb,&st,&ed);
		vector<state> gra[sv];
		int fr,to,ct;
		for(int j=0;j<cb;j++)
		{
			scanf("%d %d %d",&fr,&to,&ct);
			gra[fr].push_back(state(fr,to,ct));
			gra[to].push_back(state(to,fr,ct));
		}
		priority_queue<state> PQ;
		vis[st]=true;
		d[st]=0;
		int size_st=gra[st].size();
		for(i=0;i<size_st;i++)
		{
			PQ.push(gra[st][i]);
		}
		bool ans=false;
		while(!PQ.empty())
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			d[u.to]=u.ct;
			vis[u.to]=true;
			if(vis[ed]==true)
			{
				ans=true;
				break;
			}
			int size=gra[u.to].size();
			for(i=0;i<size;i++)
			{
				state tmp=gra[u.to][i];
				PQ.push(state(tmp.fr,tmp.to,tmp.ct+d[tmp.fr]));
			}
		}
		if(ans==true)printf("Case #%d: %d\n",k,d[ed]);
		else printf("Case #%d: unreachable\n",k);
		
	}
//	system("pause");
    return 0;
}
