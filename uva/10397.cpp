#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int,int>mp;
bool vis[800];
struct state
{
	int to;
	double ct;
	state(int tt,double tc)
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
	int N;
	int i,j,k;
	while(~scanf("%d",&N))
	{
		memset(vis,false,sizeof(vis));
		double n[800][2];
		for(i=1;i<=N;i++)
		{
			scanf("%lf %lf",&n[i][0],&n[i][1]);
		}
		vector<state>vc[800];
		for(j=1;j<N;j++)
		{
			for(k=j+1;k<=N;k++)
			{
				double dis=sqrt((n[j][0]-n[k][0])*(n[j][0]-n[k][0])+(n[j][1]-n[k][1])*(n[j][1]-n[k][1]));
				vc[j].push_back(state(k,dis));
				vc[k].push_back(state(j,dis));
			}
		}
		int sn=0;
		int M;
		mp.clear();
		scanf("%d",&M);
		priority_queue<state>PQ;
		int a,b;
		for(j=1;j<=M;j++)
		{
			scanf("%d %d",&a,&b);
			vc[a].push_back(state(b,0));
			vc[b].push_back(state(a,0));
		}
		int size_st=vc[1].size();
		for(j=0;j<size_st;j++)
		{
			PQ.push(vc[1][j]);
		}
		vis[1]=true;
		int num=N-1;
		double ans=0;
		while(!PQ.empty())
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			vis[u.to]=true;
			ans=ans+u.ct;
			num--;
			if(num==0)break;
			int size=vc[u.to].size();
			for(j=0;j<size;j++)
			{
				state tmp=vc[u.to][j];
				if(vis[tmp.to]==true)continue;
				PQ.push(vc[u.to][j]);
			}
		}
		printf("%.2lf\n",ans);
	}
    return 0;
}
