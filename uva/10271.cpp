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
#define INF 0x3f3f3f3f
#define W(a,b) ((s[a]-s[b])*(s[a]-s[b]))
using namespace std;
long long s[5010];
long long dp[5010][1010];
long long DP(int n,int k)
{
	long long &tmp=dp[n][k];
	if(tmp!=-1)return tmp;
	if(n<k*3)return tmp=INF;
	if(k==0)return tmp=0;
	tmp=min(DP(n-1,k),DP(n-2,k-1)+W(n,n-1));
	//printf("%d %d "__lld"\n",n,k,tmp);
	return tmp;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int K,N;
		scanf("%d %d",&K,&N);
		for(int i=0;i<N;i++)
		{
			scanf(__lld,&s[i+1]);
		}
		sort(s+1,s+1+N,cmp);
		//printf("   %d\n",s[1]);
		MS(dp,-1);
		//DP(3,1);
		printf(__lld"\n",DP(N,K+8));
	}
	return 0;
}

