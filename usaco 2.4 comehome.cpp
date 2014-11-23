/*
ID: allenwh1
PROG: comehome
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
#include <queue>
#include <map>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
map<char,int>mp;
struct state
{
	int t,d;
	state(int tt,int td)
	{
		t=tt,d=td;
	}
};
deque<state>dq[60];
int sn=0;
int dis[60];
char name[60];
bool vis[60];
int find(char c)
{
	if(mp.count(c)==0)
	{
		mp[c]=sn;
		name[sn++]=c;
	}
	return mp[c];
}
void push(int a,int b,int d)
{
	dq[a].push_back(state(b,d));
	dq[b].push_back(state(a,d));
}
void BFS(int s)
{
	queue<int>q;
	dis[s]=0;
	q.push(s);
	int size;
//	int size=dq[s].size();
//	for(int i=0;i<size;i++)
//	{
//		state tmp=dq[s][i];
//		dis[tmp.t]=dis[s]+tmp.d;
//		q.push(tmp.t);
//	}
//	vis[s]=true;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
//		if(vis[t])continue;
//		vis[t]=true;
		size=dq[t].size();
		for(int i=0;i<size;i++)
		{
			state tmp=dq[t][i];
			if(dis[tmp.t]>dis[t]+tmp.d/*&&!vis[tmp.t]*/)
			{
				dis[tmp.t]=dis[t]+tmp.d;
				q.push(tmp.t);
			}
		}
	}
}
int N;
const int INF=1e9;
int main()
{
	fin("comehome.in");
	fout("comehome.out");
	scanf("%d",&N);
	fill(dis,dis+60,INF);
//	memset(vis,false,sizeof(vis));
	for(int i=0;i<N;i++)
	{
		char a,b;
		int d;
		scanf(" %c %c",&a,&b);
		scanf("%d",&d);
		int aa=find(a),bb=find(b);
		push(aa,bb,d);		
	}
	int s=find('Z');
	BFS(s);
	int mn=1e9;
	int num;
	for(int i=0;i<sn;i++)
	{
		if(mn>dis[i]&&i!=s&&isupper(name[i]))
		{
			mn=dis[i];
			num=i;
		}
	}
	printf("%c %d\n",name[num],mn);
//	while(1);
    return 0;
}
