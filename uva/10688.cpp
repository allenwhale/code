#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
int dp[510][510];
int N,K;
int find(int x,int y)
{
	int &tmp=dp[x][y];
	if(tmp!=-1);
	else if(x<=1)tmp=0;
	else
	{	
		tmp=INF;
		for(int i=1;i<=x;i++)
		{
			tmp=min(tmp,x*(y+i)+find(i-1,y)+find(x-i,y+i));
		}
	}
	//printf("%d %d %d\n",x,y,tmp);
	return tmp;
}
int main()
{
	int T;
	int t=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&K);
		MS(dp,-1);
		printf("Case %d: %d\n",t++,find(N,K));
	}
	return 0;
}

