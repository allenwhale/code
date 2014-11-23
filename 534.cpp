#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
struct state
{
	int fr,to;
	float ct;
	state(int tf,int tt,float tc)
	{
		fr=tf;
		to=tt;
		ct=tc;
	}
	bool operator < (const state &n) const
	{
		if(ct<n.ct)return false;
		return true;
	}
};
bool vis[210];
float d[210];
int main()
{
	int N;
	int i,j;
	int number=0;
	while(~scanf("%d",&N) && N)
	{
		number++;
		float fx,fy,tx,ty;
		float stone[210][2];
		vector<state>vc[210];
		scanf("%f %f",&fx,&fy);
		stone[0][0]=fx;
		stone[0][1]=fy;
		scanf("%f %f",&tx,&ty);
		stone[1][0]=tx;
		stone[1][1]=ty;
		for(i=2;i<N;i++)
		{
			scanf("%f %f",&stone[i][0],&stone[i][1]);
		}
//		getchar();
//		getchar();
		int num=i-1;
		for(i=0;i<num;i++)
		{
			for(j=i+1;j<=num;j++)
			{
				float dis=sqrt((stone[i][0]-stone[j][0])*(stone[i][0]-stone[j][0])+(stone[i][1]-stone[j][1])*(stone[i][1]-stone[j][1]));
				vc[i].push_back(state(i,j,dis));
				vc[j].push_back(state(j,i,dis));			
			}
		}
		priority_queue<state>PQ;
		int size_st=vc[0].size();
		for(i=0;i<size_st;i++)
		{
			PQ.push(vc[0][i]);
		}
		memset(vis,false,sizeof(vis));
		memset(d,0,sizeof(d));
		vis[0]=true;
		while(1)
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			vis[u.to]=true;
			if(d[u.fr]<u.ct)d[u.to]=u.ct;
			else d[u.to]=d[u.fr];
			if(u.to==1)break;
			int size=vc[u.to].size();
			for(i=0;i<size;i++)
			{
				state tmp=vc[u.to][i];
				if(vis[tmp.to]==true)continue;
				PQ.push(vc[u.to][i]);
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",number,d[1]);
	}
    return 0;
}
