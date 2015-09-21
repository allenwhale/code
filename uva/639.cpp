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
char mp[5][5];
int MAXN;
int N;
bool isok(int x,int y)
{
	for(int i=x;i>=0;i--)
	{
		if(mp[i][y]=='O')return false;
		if(mp[i][y]=='X')break;
	}
	for(int i=x;i<N;i++)
	{
		if(mp[i][y]=='O')return false;
		if(mp[i][y]=='X')break;
	}
	for(int i=y;i>=0;i--)
	{
		if(mp[x][i]=='O')return false;
		if(mp[x][i]=='X')break;
	}
	for(int i=y;i<N;i++)
	{
		if(mp[x][i]=='O')return false;
		if(mp[x][i]=='X')break;
	}
	return true;
}
void dfs(int x,int y,int n)
{
	MAXN=max(MAXN,n);
	if(x==N)return;
	else if(y==N)dfs(x+1,0,n);
	else
	{
		if(mp[x][y]=='X')dfs(x,y+1,n);
		else
		{
			if(isok(x,y))
			{
				mp[x][y]='O';
				dfs(x,y+1,n+1);
				mp[x][y]='.';
			}
			dfs(x,y+1,n);
		}
	}
}
int main()
{
	
	while(~scanf("%d",&N)&&N)
	{
		MAXN=0;
		for(int i=0;i<N;i++)
		{
			scanf("%s",mp[i]);
		}
		dfs(0,0,0);
		printf("%d\n",MAXN);
	}
	return 0;
}

