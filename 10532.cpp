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
long long dp[100][100];
int s[100],cnt[100];
int N,Q,M;
void _find()
{
	MS(dp,0ll);
	dp[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=N;j++)dp[i][j]=dp[i-1][j];
		for(int j=0;j<=N;j++)
		{
			for(int k=1;k<=cnt[i];k++)
				if(j-k>=0)dp[i][j]+=dp[i-1][j-k];
		}
	}
}
void init()
{
	MS(dp,-1ll);
	MS(cnt,0);
	dp[0][0]=1ll;
}
int main()
{
	int t=1;
	while(~scanf("%d %d",&N,&Q)&&N)
	{
		init();
		int mx=0;
		for(int i=1;i<=N;i++)
			scanf("%d",&s[i]),cnt[s[i]]++,mx=max(mx,s[i]);
		printf("Case %d:\n",t++);
		_find();
		while(Q--) 
		{
			scanf("%d",&M);
			printf(__lld"\n",dp[N][M]);
		}
	}
	return 0;
}

