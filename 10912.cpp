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
int dp[30][360];
int main()
{
	MS(dp,0);
	dp[0][0]=1;
	for(int i=1;i<=26;i++)
	{
		for(int j=26;j>0;j--)
		{
			for(int k=352;k>=i;k--)
			{
				dp[j][k]+=dp[j-1][k-i];
			}
		}
		//printf("%d\n",dp[8][100]);
	}
	int L,S,t=1;
	while(~scanf("%d %d",&L,&S)&&S&&L)
	{
		printf("Case %d: ",t++);
		if(L>26||S>351)printf("0\n");
		else printf("%d\n",dp[L][S]);
	}
	return 0;
}

