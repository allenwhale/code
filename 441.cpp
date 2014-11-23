#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
using namespace std;
int N;
int s[13];
bool vis[13];
vector<int>vc;
void show()
{
	foreach(it,vc)
	{
		printf("%d%c",(*it),it==vc.end()-1?'\n':' ');
	}
}
void dfs(int idx,int now)
{
	//printf("%d %d %d\n",N,idx,now);
	//system("pause");
	if(now==6)
	{
		show();
	}
	for(int i=idx;i<N;i++)
	{
		//if(vis[i])continue;
		vis[i]=true;
		vc.push_back(s[i]);
		dfs(i+1,now+1);
		vis[i]=false;
		vc.pop_back();
	}
}
int main()
{
	int t=0;
	while(~scanf("%d",&N)&&N)
	{
		if(t++)puts("");
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
		}
		dfs(0,0);
	}
	return 0;
}

