#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
char name[30][30];
map<string,int>mp;
int sn=0;
vector<int>vc1[30];
vector<int>vc2[30];
vector<int>stp;
vector<int>cir;
int N,M;
bool vis[30];
void init()
{
	mp.clear();
	sn=0;
	for(int i=0;i<30;i++)
	{
		vc1[i].clear();
		vc2[i].clear();
	}
	stp.clear();
}
int find(char s[])
{
	if(mp.count(s)==0)
	{
		strcpy(name[sn],s);
		mp[s]=sn++;
	}
	return mp[s];
}
void dfs(int x)
{
	
	int sz=vc1[x].size();
	for(int i=0;i<sz;i++)
	{
		int to=vc1[x][i];
		if(vis[to])continue;
		vis[to]=true;
		dfs(to);
		//vis[to]=false;
	}
	stp.push_back(x);
}
void dfs2(int x)
{
	
	int sz=vc2[x].size();
	for(int i=0;i<sz;i++)
	{
		int to=vc2[x][i];
		if(vis[to])continue;
		vis[to]=true;
		dfs2(to);
	}
	cir.push_back(x);
}
int main()
{
	int T=0;
	while(~scanf("%d %d",&N,&M)&&N)
	{
		init();
		for(int i=0;i<M;i++)
		{
			char n1[30],n2[30];
			scanf("%s %s",n1,n2);
			int no1=find(n1),no2=find(n2);
			vc1[no1].push_back(no2);
			vc2[no2].push_back(no1);
		}
		if(T)puts("");
		printf("Calling circles for data set %d:\n",++T);
		MS(vis,false);
		for(int i=0;i<N;i++)
		{
			if(!vis[i])
			{
				vis[i]=true;
				dfs(i);
			}
		}
		MS(vis,false);
		for(int i=N-1;i>=0;i--)
		{
			if(!vis[stp[i]])
			{
				cir.clear();
				vis[stp[i]]=true;
				dfs2(stp[i]);
				int sz=cir.size();
				for(int j=0;j<sz;j++)
				{
					printf("%s%s",name[cir[j]],j==sz-1?"\n":", ");
				}
			}
		}
	}
	return 0;
}

