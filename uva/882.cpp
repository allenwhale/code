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
int dp[15][110][110];
int find(int x,int y,int z)
{
	int &tmp=dp[x][y][z];
	if(tmp!=-1)return tmp;
	
	//if(y>z)return tmp=0;
	if(y==z)return tmp=0;
	if(x==0)return tmp=INF;
	//if(x==1)return tmp=((y+z)*(z-y+1))/2;
	tmp=INF;
	for(int i=y+1;i<=z;i++)
	{
		tmp=min(tmp,i+max(find(x-1,y,i-1),find(x,i,z)));
	}
	return tmp;
}
int main()
{
	MS(dp,-1);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",find(x,0,y));
	}
	return 0;
}

