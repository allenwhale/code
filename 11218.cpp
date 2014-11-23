#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
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
map<int,int>mp;
int s[90];
int MX=0;
bool vis[10];
int N;
void dfs(int idx,int now,int score)
{
	if(now==3)
	{
		MX=max(MX,score);
		return ;
	}
	for(int i=idx;i<N;i++)
	{
		int a=s[i]/100,b=(s[i]-100*a)/10,c=s[i]%10;
		if(!vis[a]&&!vis[b]&&!vis[c])
		{
			vis[a]=vis[b]=vis[c]=true;
			dfs(i+1,now+1,score+mp[s[i]]);
			vis[a]=vis[b]=vis[c]=false;
		}
	}
}
int main()
{
	int T=1;
	while(~scanf("%d",&N)&&N)
	{
		MX=0;
		mp.clear();
		for(int i=0;i<N;i++)
		{
			int a,b,c,ss;
			scanf("%d %d %d %d",&a,&b,&c,&ss);
			int num=100*a+10*b+c;
			mp[num]=ss;
			s[i]=num;
		}
		dfs(0,0,0);
		printf("Case %d: ",T++);
		if(MX)printf("%d\n",MX);
		else printf("-1\n");
	}
	return 0;
}

