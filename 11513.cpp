#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <time.h>
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
int dis[362900];
bool vis[362900];
map<string,int>mp[1000000];
int sn;
struct sta
{
	char s[10];
	int d;
	sta(){};
	sta(char _s[],int _d)
	{
		strcpy(s,_s);
		d=_d;
	}
};
struct Route
{
	int n;
	char c;
	Route(){}
	Route(int _n,char _c)
	{
		n=_n,c=_c;
	}
}route[362900];
inline int find(char s[])
{
	int num=100000*(s[0]-'0')+10000*(s[1]-'0')+1000*(s[2]-'0')+
			100*(s[3]-'0')+10*(s[4]-'0')+(s[5]-'0');
	if(mp[num].count(s)==0)
	{
		mp[num][s]=sn++;
	}
	return mp[num][s];
}
void BFS()
{	
	#ifdef __ALLEN
	int time=clock();
	#endif
	MS(vis,false);
	MS(dis,0x3f);
	queue<sta>pq;
	char ss[]="123456789";
	pq.push(sta(ss,0));
	dis[find(ss)]=0;
	while(!pq.empty())
	{
		sta tmp=pq.front();
		pq.pop();
		char ts[10],tos[10];
		int tn;
		strcpy(ts,tmp.s);
		tn=find(ts);
		if(vis[tn])continue;
		vis[tn]=true;
		//H
		for(int i=0;i<3;i++)
		{
			strcpy(tos,ts);
			int h=i*3;
			swap(tos[h+2],tos[h+1]),swap(tos[h],tos[h+2]);
			int ton=find(tos);
			if(!vis[ton]&&dis[ton]>dis[tn]+1)
			{
				dis[ton]=dis[tn]+1;
				route[ton]=Route(i+1,'H');
				pq.push(sta(tos,dis[ton]));
			}
		}
		//V
		for(int i=0;i<3;i++)
		{
			strcpy(tos,ts);
			swap(tos[i],tos[i+3]),swap(tos[i],tos[i+6]);
			int ton=find(tos);
			if(!vis[ton]&&dis[ton]>dis[tn]+1)
			{
				dis[ton]=dis[tn]+1;
				route[ton]=Route(i+1,'V');
				pq.push(sta(tos,dis[ton]));
			}
		}
	}
	#ifdef __ALLEN
	printf("%d\n",clock()-time);
	#endif
}

int main()
{
	BFS();
	char s[10];
	int n;
	char t[]="123456789\0";
	while(~scanf("%d",&n)&&n)
	{
		s[0]=n+'0';
		for(int i=1;i<9;i++)
		{
			scanf("%d",&n);
			s[i]=n+'0';
		}
		s[9]=0;
		int ans=dis[find(s)];
		if(ans==INF)
		{
			puts("Not solvable");
			continue;
		}
		if(ans==0)
		{
			puts("0");
			continue;
		}
		printf("%d ",ans);
		vector<Route>vc;
		char tmp[10];
		strcpy(tmp,s);
		while(strcmp(tmp,t)!=0)
		{
			int tn=find(tmp);
			vc.push_back(route[tn]);
			if(route[tn].c=='H')
			{
				int h=3*(route[tn].n-1);
				swap(tmp[h],tmp[h+1]),swap(tmp[h],tmp[h+2]);
			}
			else if(route[tn].c=='V')
			{
				int h=route[tn].n-1;
				swap(tmp[h+6],tmp[h+3]),swap(tmp[h],tmp[h+6]);
			}
		}
		foreach(it,vc)
		{
			printf("%c%d",(*it).c,(*it).n);
		}
		puts("");
	}
	return 0;
}

