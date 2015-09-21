#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int s[70];
bool vis[70];
int sum;
int N;
bool dfs(int now,int idx,int cnt,int goal)
{
	if(cnt*goal==sum)return true;
	for(int i=idx;i<N;i++)
	{
		if(vis[i]||(i&&!vis[i-1]&&s[i]==s[i-1]))continue;
		if(now+s[i]==goal)
		{
			vis[i]=true;
			if(dfs(0,0,cnt+1,goal))return true;
			vis[i]=false;
			return false;
		}
		else if(now+s[i]<goal)
		{
			vis[i]=true;
			if(dfs(now+s[i],i+1,cnt,goal))return true;
			vis[i]=false;
			if(now==0)return false;
		}
	}
	return false;
}
inline bool cmp(int a,int b)
{
	return a>b;
}
int main()
{	
	while(~scanf("%d",&N)&&N)
	{
		sum=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i];
		}
		sort(s,s+N,cmp);
		
		int ans=-1;
		for(int i=s[0];i<=sum;i++)
		{
			if(sum%i==0)
			{
				MS(vis,false);
				if(dfs(0,0,0,i))
				{
					ans=i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

