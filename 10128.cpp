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
int dp[15][15][15];
void _find()
{
	for(int n=2;n<=13;n++)
	{
		for(int p=1;p<=n;p++)
		{
			for(int q=1;q<=n;q++)
			{
				dp[n][p][q]=dp[n-1][p][q]*(n-2)+dp[n-1][p-1][q]+dp[n-1][p][q-1];
			}
		}
	}
}
int main()
{
	MS(dp,0);
	dp[1][1][1]=1;
	_find();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,p,q;
		scanf("%d %d %d",&n,&p,&q);
		printf("%d\n",dp[n][p][q]);
	}
	return 0;
}

