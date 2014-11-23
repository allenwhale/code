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
#define K 51
using namespace std;
int N,M;
int s[110];
bool dp[5100*2][51];

int main()
{
	while(~scanf("%d %d",&N,&M))
	{
		int sum=0;
		for(int i=0;i<N+M;i++)
		{
			scanf("%d",&s[i]);
			s[i]+=K;
			sum+=s[i];
		}
		MS(dp,false);
		dp[0][0]=true;
		for(int i=0;i<N+M;i++)
		{
			for(int j=sum;j>=s[i];j--)
			{
				for(int k=1;k<=N;k++)
				{
					dp[j][k]|=dp[j-s[i]][k-1];
				}
			}
		}
		int mn=INF,mx=-INF;
		for(int i=0;i<sum;i++)
		{
			if(dp[i][N]==false)continue;
			int tmp=(i-K*N)*(sum-i-K*M);
			mn=min(mn,tmp);
			mx=max(mx,tmp);
		}
		printf("%d %d\n",mx,mn);
	}
	return 0;
}

