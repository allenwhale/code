#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
#define INF 10000000
using namespace std;
bool vis[110];
struct state
{
	int to,ct;
	state(int tt,int tc)
	{
		to=tt;
		ct=tc;
	}
	bool operator < (const state &n) const
	{
		if(ct<n.ct)return true;
		return false;
	}
};
int main()
{
	int N;
	scanf("%d",&N);
	int i,j,k;
	for(i=1;i<=N;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		vector<state>vc[110];
		for(j=1;j<=m;j++)
		{
			int fr,to,ct;
			scanf("%d %d %d",&fr,&to,&ct);
			vc[fr].push_back(state(to,ct));
			vc[to].push_back(state(fr,ct));
		}
		priority_queue<state>PQ;
		int size_0=vc[0].size();
		for(j=0;j<size_0;j++)
		{
			PQ.push(vc[0][j]);
		}
		int mn=INF;
		int j=0;
		memset(vis,false,sizeof(vis));
		vis[0]=true;
		while(j<n-1)
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			vis[u.to]=true;
			if(mn>u.ct)mn=u.ct;
			j++;
			int size=vc[u.to].size();
			for(k=0;k<size;k++)
			{
				state tmp=vc[u.to][k];
				if(vis[tmp.to]==true)continue;
				PQ.push(vc[u.to][k]);
			}
		}
		printf("Case #%d: %d\n",i,mn);
	}
    return 0;
}
