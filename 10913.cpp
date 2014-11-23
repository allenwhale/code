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
#define MAX3(a,b,c) max(max(a,b),c)
#define MAX4(a,b,c,d) max(max((a),(b)),max((c),(d)))
const long long LLINF=(long long)INF*(long long)INF;
using namespace std;
int N,K;
long long mp[80][80];
long long dp[80][80][10][5];
/*
v=1 up
v=2 left
v=3 right
*/
long long DP(int x,int y,int k,int v)
{
	long long &tmp=dp[x][y][k][v];
	if(tmp!=-1ll)return tmp;
	if(mp[x][y]<0)k--;
	if(k<0)return tmp=-LLINF;
	if(x==0&&y==0)return tmp=mp[x][y];
	tmp=-LLINF;
	if(v==1)
	{
		if(x==0)return tmp=-LLINF;
		tmp=mp[x][y]+MAX4(tmp,DP(x-1,y,k,1),DP(x-1,y,k,2),DP(x-1,y,k,3));
	}
	else if(v==2)
	{
		if(y==0)return tmp=-LLINF;
		tmp=mp[x][y]+MAX3(tmp,DP(x,y-1,k,1),DP(x,y-1,k,2));
	}
	else if(v==3)
	{
		if(y==N-1)return tmp=-LLINF;
		tmp=mp[x][y]+MAX3(tmp,DP(x,y+1,k,1),DP(x,y+1,k,3));
	}
	//printf("%d %d %d %d %I64d\n",x,y,k,v,tmp);
	return tmp;
}
int main()
{
	int t=1;
	while(~scanf("%d %d",&N,&K)&&N)
	{
		MS(dp,-1ll);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				scanf(__lld,&mp[i][j]);
		long long ans=max(DP(N-1,N-1,K,1),DP(N-1,N-1,K,2));
		printf("Case %d: ",t++);
		if(ans>=-LLINF+(int)1e9)printf(__lld"\n",ans);
		else printf("impossible\n");
	}
	return 0;
}

