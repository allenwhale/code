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
int N,w[1010],p[1010],dp[50];
int main()
{
	int T_;
	scanf("%d",&T_);
	while(T_--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d %d",&p[i],&w[i]);
		MS(dp,0);
		for(int i=0;i<N;i++)
		{
			for(int j=30;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
			}
		}
		int G;
		scanf("%d",&G);
		int ans=0;
		while(G--)
		{
			int tmp;
			scanf("%d",&tmp);
			ans+=dp[tmp];
		}
		printf("%d\n",ans);
	}
	return 0;
}

