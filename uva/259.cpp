#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
/*
0: source
1~26: program
30~39: computer
40: target

source->computer->program->target
*/
#define Source 0
#define Target 40

struct Edge
{
	int to,r,rev;
	Edge(){}
	Edge(int _t,int _r,int _rev)
	{
		to=_t,r=_r,rev=_rev;
	}
};
vector<Edge>vc[50];
void add(int a,int b,int c)
{
	//printf("%d %d %d\n",a,b,c);
	vc[a].push_back(Edge(b,c,SIZE(vc[b])));
	vc[b].push_back(Edge(a,0,SIZE(vc[a])-1));
}
int d[50];
bool vis[50];
int link[50];
int BFS(int s,int t)
{
	MS(d,-1);
	MS(vis,false);
	d[s]=0;
	vis[s]=true;
	queue<int>q;
	q.push(Source);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		//printf("  %d\n",u);
		foreach(it,vc[u])
		{
			Edge tmp=(*it);
			int v=tmp.to,r=tmp.r;
			if(!vis[v]&&r>0)
			{
				//printf(" %d %d %d\n",u,v,r);
				vis[v]=true;
				d[v]=d[u]+1;
				if(v==t)return d[t];
				q.push(v);
			}
		}
	}
	return Target+1;
}
int DFS(int v,int df,int s,int t)
{
	//printf("dfs %d\n",v);
	if(v==Target)return df;
	if(vis[v])return 0;
	vis[v]=true;
	int f=-1;
	foreach(it,vc[v])
	{
		Edge &tmp=*(it);
		int u=tmp.to,r=tmp.r,rev=tmp.rev;
		//printf("%d %d %d\n",v,u,r);
		if(d[u]==d[v]+1&&r>0)
		{
			if((f=DFS(u,min(df,r),Source,Target)))
			{
				//printf("  %d %d %d\n",v,u,f);
				link[v]=u;				
				vc[v][vc[u][rev].rev].r-=f;
				//printf("test %d\n",vc[v][vc[u][rev].rev].r);
				vc[u][rev].r+=f;
				return f;	
			}
		}
	}
	return 0;
}
int Dinic()
{
	int flow=0;
	int tmp;
	while((tmp=BFS(Source,Target))<Target)
	{
		//printf(" %d\n",tmp);
		//puts("BFS");
		//system("pause");
		int f;
		
		while(true)
		{
			MS(vis,false);
			f=DFS(Source,INF,Source,Target);
			if(!f)break;
			//printf("%d\n",f);
		//	puts("add flow");	
			//system("pause");
			flow+=f;
			//MS(vis,false);
		}
	};
	return flow;
}
void init()
{
	for(int i=0;i<50;i++)
		vc[i].clear();
	MS(link,-1);
}
int main()
{
	char tmp[100];
	while(gets(tmp)!=NULL&&strcmp(tmp,"")!=0)
	{
		init();
		int all=0;
		do
		{
			int program=tmp[0]-'A'+1;
			int num=tmp[1]-'0';
			all+=num;
			add(program,Target,num);
			for(int i=3;tmp[i]!=';';i++)
			{
				int usecom=tmp[i]-'0'+30;
				//printf("%c %d\n",tmp[0],usecom-30);
				add(usecom,program,1);
				//add(Source,usecom,1);
			}
		}while(gets(tmp)!=NULL&&strcmp(tmp,"")!=0);
		for(int i=30;i<40;i++)
		{
			add(Source,i,1);
		}
		int flow=Dinic();
		if(flow!=all)puts("!");
		else
		{
			for(int i=30;i<40;i++)
			{
				printf("%c",link[i]!=-1?link[i]-1+'A':'_');
			}
			puts("");
		}
	}
	return 0;
}

