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
int dp[50][3];
int main()
{
	dp[1][0]=1;
	dp[1][1]=1;
	dp[2][0]=2;
	dp[2][1]=1;
	dp[2][2]=1;
	for(int i=3;i<=30;i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][1];
	}
	int N;
	while(~scanf("%d",&N)&&N)
	{
		if(N>1)printf("%d\n",(1<<N)-(dp[N][0]+dp[N][1]+dp[N][2]));
		else printf("0\n");
	}
	return 0;
}

