#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
bool isprime[]={0,0,1,1,0,1,0,1,0,0,0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0};
              //0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
bool vis[20];
vector<int>vc;
int N;
void dfs(int now)
{
	if(now==N)
	{
		if(isprime[vc[0]+vc[N-1]])
		{
			foreach(it,vc)
			{
				printf("%d%c",*(it),it==vc.end()-1?'\n':' ');
			}
		}
		return;
	}
	for(int i=2;i<=N;i++)
	{
		if(vis[i])continue;
		if(isprime[i+vc[now-1]])
		{
			vis[i]=true;
			vc.push_back(i);
			dfs(now+1);
			vc.pop_back();
			vis[i]=false;
		}
	}
}
int main()
{
	int T=0;
	while(~scanf("%d",&N))
	{
		if(T++)puts("");
		vc.clear();
		vc.push_back(1);
		MS(vis,false);
		printf("Case %d:\n",T);
		dfs(1);
		
	}
	return 0;
}

