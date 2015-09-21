#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int N;
vector<int>vc[110];
int dis[110],low[110];
int t;
int cnt;
void init()
{
	for(int i=0;i<110;i++)
		vc[i].clear();
	MS(dis,0);
	MS(low,0);
	t=0;
	cnt=0;
}
void dfs(int p,int x)
{
	dis[x]=low[x]=++t;
	int sz=vc[x].size();
	int child=0;
	bool tf=false;
	for(int i=0;i<sz;i++)
	{
		int to=vc[x][i];
		if(to==p)continue;
		if(dis[to])
		{
			low[x]=min(low[x],dis[to]);
		}
		else
		{
			child++;
			dfs(x,to);
			low[x]=min(low[x],low[to]);
			if(low[to]>=dis[x])tf=true;
		}
	}
	if((x==p&&child>1)||(x!=p&&tf))cnt++;
}
int main()
{
	while(~scanf("%d%*c",&N)&&N)
	{
		
		init();
		char s[1000];
		//puts("in");
		while(gets(s)!=NULL&&s[0]!='0')
		{
			char *ptr=strtok(s," ");
			int f,tmp;
			sscanf(ptr,"%d",&f);
			ptr=strtok(NULL," ");
			while(ptr!=NULL)
			{
				sscanf(ptr,"%d",&tmp);
				vc[f].push_back(tmp);
				vc[tmp].push_back(f);
				ptr=strtok(NULL," ");
			}
		}
		dfs(1,1);
		printf("%d\n",cnt);
	}
	return 0;
}

