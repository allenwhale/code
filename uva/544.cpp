#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#define INF 100000000
using namespace std;
bool vis[210];
int d[210];
map<string,int>mp;
int sn;
int find(char s[])
{
	if(mp.count(s)==0)
	{
		mp[s]=sn;
		sn++;
	}
	return mp[s];
}
struct state
{
	int to,ct,fr;
	state(int tf,int tt,int tc)
	{
		fr=tf;
		to=tt;
		ct=tc;
	}
	bool operator <(const state &n)const
	{
		if(ct<n.ct)return true;
		return false;
	}
};
int main()
{
	int i;
	int n,m;
	int num=0;
	while(1)
	{
		num++;
		scanf("%d %d",&n,&m);
		if(n==m&&n==0)break;
		char a[20],b[20];
		int ct;
		vector<state>vc[210];
		for(i=1;i<=m;i++)
		{
			scanf("%s %s %d",a,b,&ct);
			int ta=find(a);
			int tb=find(b);
			vc[ta].push_back(state(ta,tb,ct));
			vc[tb].push_back(state(tb,ta,ct));
		}
		scanf("%s %s",a,b);
		int st=find(a);
		int ed=find(b);
		priority_queue<state>PQ;
		int size_st=vc[st].size();
		for(i=0;i<size_st;i++)
		{
			PQ.push(vc[st][i]);
		}
		memset(vis,false,sizeof(vis));
		for(i=0;i<210;i++)
		{
			d[i]=INF;
		}
		vis[st]=true;
		while(1)
		{
			state u=PQ.top();
			PQ.pop();
			if(vis[u.to]==true)continue;
			vis[u.to]=true;
			if(u.ct<d[u.fr])d[u.to]=u.ct;
			else d[u.to]=d[u.fr];
			if(u.to==ed)break;
			int size=vc[u.to].size();
			for(i=0;i<size;i++)
			{
				state tmp=vc[u.to][i];
				if(vis[tmp.to]==true)continue;
				PQ.push(vc[u.to][i]);
			}
		}
		printf("Scenario #%d\n%d tons\n\n",num,d[ed]);
	}
    return 0;
}
