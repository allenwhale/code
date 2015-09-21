#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXT 10010
using namespace std;
int n,m,t;
int dp[MAXT];
int use[MAXT];
void pack(int s)
{
	for(int i=0;i+s<=t;i++)
	{
		if(use[i+s]<use[i]+s)
		{
			dp[i+s]=dp[i]+1;
			use[i+s]=use[i]+s;
		}
	}
}
int main()
{
	while(~scanf("%d %d %d",&n,&m,&t))
	{
		if(n>m)swap(n,m);
		memset(dp,0,sizeof(dp));
		memset(use,0,sizeof(use));
		pack(n);
		pack(m);
		if(use[t]==t)printf("%d\n",dp[t]);
		else printf("%d %d\n",dp[use[t]],t-use[t]);
	}
	return 0;
}
