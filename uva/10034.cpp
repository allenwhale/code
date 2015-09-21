#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool vis[110];
struct state
{
	int to;
	float ct;
	state(int tt,float tc)
	{
		to=tt;
		ct=tc;
	}
	bool operator < (const state &n)const
	{
		if(ct<n.ct)return false;
		return true;
	}
};
int main()
{
	int N,node;
	float n[110][2];
	int i,j,k;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&node);
		for(j=0;j<node;j++)
		{
			scanf("%f %f",&n[j][0],&n[j][1]);
		}
		vector<state>vc[110];
		for(j=0;j<node-1;j++)
		{
			for(k=j+1;k<node;k++)
			{
				float dis=sqrt((n[j][0]-n[k][0])*(n[j][0]-n[k][0])+(n[j][1]-n[k][1])*(n[j][1]-n[k][1]));
				vc[j].push_back(state(k,dis));
				vc[k].push_back(state(j,dis));
			}
		}
		priority_queue<state>PQ;
		int size_0=vc[0].size();
		for(j=0;j<size_0;j++)
		{
			PQ.push(vc[0][j]);
		}
		memset(vis,false,sizeof(vis));
		vis[0]=true;
		float ans=0;
		int num=0;
		while(num<node-1)
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			vis[u.to]=true;
			ans=ans+u.ct;
			num++;
			int size=vc[u.to].size();
			for(j=0;j<size;j++)
			{
				state tmp=vc[u.to][j];
				if(vis[tmp.to]==true)continue;
				PQ.push(vc[u.to][j]);
			}
		}
		printf("%.2f\n",ans);
		if(i<N)printf("\n");
	}
    return 0;
}
