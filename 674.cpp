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
//7489
int dp[7500];
int x[]={1,5,10,25,50};
int main()
{
	dp[0]=1;
	for(int i=0;i<5;i++)
	{
		for(int j=x[i];j<=7489;j++)
		{
			dp[j]+=dp[j-x[i]];
		}
	}
	int N;
	while(~scanf("%d",&N))
	{
		printf("%d\n",dp[N]);
	}
	return 0;
}

