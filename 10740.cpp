#include <string.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int d[110][15];
int pn[110];
#define INF 10000000
struct state
{
	int to;
	int ct;
	state(int tt,int tc)
	{
		to=tt;
		ct=tc;
	}
	bool operator <(const state &n) const
	{
		if(ct<n.ct)return false;
		return true;
	}
};
int main()
{
	int n,m;
	int i,j;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==m&&n==0)break;
		int st,ed,time;
		scanf("%d %d %d",&st,&ed,&time);
		vector<state>vc[110];
		for(i=1;i<=m;i++)
		{
			int fr,to,ct;
			scanf("%d %d %d",&fr,&to,&ct);
			vc[fr].push_back(state(to,ct));
		}
		priority_queue<state>PQ;
		int size_st=vc[st].size();
		for(i=0;i<size_st;i++)
		{
			PQ.push(vc[st][i]);
		}
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=time+1;j++)
			{
				d[i][j]=INF;
			}
		}
		memset(pn,0,sizeof(pn));
		pn[st]=1;
		d[st][pn[st]]=1;
		while(!PQ.empty())
		{
			state u=PQ.top();
			PQ.pop();
			if(pn[u.to]>=time)continue;
			pn[u.to]++;
			d[u.to][pn[u.to]]=u.ct;
			if(pn[ed]==time)
			{
				break;
			}
			int size=vc[u.to].size();
			for(i=0;i<size;i++)
			{
				state tmp=vc[u.to][i];
				if(pn[tmp.to]<time&&d[tmp.to][pn[tmp.to]+1]>tmp.ct+d[u.to][pn[u.to]])
				{
					PQ.push(state(tmp.to,tmp.ct+d[u.to][pn[u.to]]));
				}
			}
		}
		if(d[ed][time]==INF)printf("-1\n");
		else printf("%d\n",d[ed][time]);
	}
    return 0;
}
