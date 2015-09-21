#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;
int d[110];
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
		if(ct<n.ct)return false;
		return true;
	}
};
int main()
{
	int el,to;
	int elct[110];
	int i,j,k,l,n,m,o,p,q,r,s;
	while(~scanf("%d %d",&el,&to))
	{	
		memset(elct,0,sizeof(elct));
		for(i=0;i<el;i++)
		{
			scanf("%d",&elct[i]);
		}
		vector<state>vc[110];
		getchar();
		char s[500];
		for(j=0;j<el;j++)
		{
			gets(s);
			char *ptr=strtok(s," ");
			int num[100];
			k=0;
			do
			{
				sscanf(ptr,"%d",&num[k]);
				k++;
			}while(ptr=strtok(NULL," "));
			for(l=0;l<k-1;l++)
			{
				for(m=l+1;m<k;m++)
				{
					vc[num[l]].push_back(state(num[m],elct[j]*abs(num[l]-num[m])+60));
					vc[num[m]].push_back(state(num[l],elct[j]*abs(num[l]-num[m])+60));
				}
			}
		}
		if(to == 0)
		{
			printf("0\n");
			continue;
		}
		priority_queue<state>PQ;
		int st=0;
		int size_st=vc[st].size();
		for(i=0;i<size_st;i++)
		{
			state tmp=vc[st][i];
			PQ.push(state(tmp.to,tmp.ct));
		}
		for(i=0;i<110;i++)
		{
			d[i]=INF;
		}
		memset(vis,false,sizeof(vis));
		vis[st]=true;
		d[st]=0;
		while(!PQ.empty())
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			d[u.to]=u.ct;
			if(u.to==to)break;
			vis[u.to]=true;
			int size=vc[u.to].size();
			for(n=0;n<size;n++)
			{
				state tmp=vc[u.to][n];
				if(vis[tmp.to]==false && u.ct+tmp.ct < d[tmp.to])
				{
					d[tmp.to] = u.ct+tmp.ct;
					PQ.push(state(tmp.to,d[tmp.to]));
				}
				
			}
		}
		
		if(d[to]==INF)printf("IMPOSSIBLE\n");
		else printf("%d\n",d[to]-60);
	}
    return 0;
}
