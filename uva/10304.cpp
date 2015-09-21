#include <stdio.h>
#include <string.h>
#define MAXN 300
#define SUM(a,b) (sum[(b)]-sum[(a)-1])
#define min(a,b) ((a)<(b)?(a):(b))
int N,s[MAXN];
int sum[MAXN];
int dp[MAXN][MAXN];
int find(int l,int r)
{
	int &tmp=dp[l][r];
	if(tmp!=-1)return tmp;
	if(l==r)return tmp=s[l];
	if(l>r)return tmp=0;
	tmp=0x3f3f3f3f;
	for(int i=l;i<=r;i++)
	{
		tmp=min(tmp,SUM(l,r)+find(l,i-1)+find(i+1,r));
	}
	return tmp;
}
int main()
{
	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&s[i]);
		}
		for(int i=1;i<=N;i++)
		{
			sum[i]=sum[i-1]+s[i];
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",find(1,N)-SUM(1,N));
	}
	#ifdef __ALLEN
	while(1);
	#endif
	return 0;
}