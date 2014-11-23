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
int sn=0;
bool vis[800];
struct state
{
	int to,fr;
	float ct;
	state(int tf,int tt,float tc)
	{
		fr=tf;
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
	int N,M;
	float n[800][2];
	int i,j,k;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		memset(n,0,sizeof(n));
		int node;
		scanf("%d",&node);
		for(j=1;j<=node;j++)
		{
			scanf("%f %f",&n[j][0],&n[j][1]);
		}
		vector<state>vc[800];
		for(j=1;j<=node-1;j++)
		{
			for(k=j+1;k<=node;k++)
			{
				float dis=sqrt((n[j][0]-n[k][0])*(n[j][0]-n[k][0])+(n[j][1]-n[k][1])*(n[j][1]-n[k][1]));
				vc[j].push_back(state(j,k,dis));
				vc[k].push_back(state(k,j,dis));
			}
		}
		memset(vis,false,sizeof(vis));
		priority_queue<state>PQ;
		scanf("%d",&M);
		mp.clear();
		sn=0;
		for(j=1;j<=M;j++)
		{
			int a,b,size;
			scanf("%d %d",&a,&b);
			vc[a].push_back(state(a,b,0));
			vc[b].push_back(state(b,a,0));
		}
		int size_st=vc[1].size();
		for(j=0;j<size_st;j++)
		{
			PQ.push(vc[1][j]); 
		}
		vis[1]=true;
		float ans=0;
		int num=node-1;
		while(!PQ.empty())
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			vis[u.to]=true;
			ans=ans+u.ct;
			num--;
			if(u.ct!=0)	printf("%d %d\n",u.fr,u.to);
			if(num==0)break;
			int size=vc[u.to].size();
			for(j=0;j<size;j++)
			{
				state tmp=vc[u.to][j];
				if(vis[tmp.to]==true)continue;
				PQ.push(vc[u.to][j]);
			}
		}
		if(ans==0)printf("No new highways need\n");
		if(i<N)printf("\n");
	}
	//while(1);
    return 0;
}
