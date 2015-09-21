/*
ID: allenwh1
PROG: inflate
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
int main()
{
	fin("inflate.in");
	fout("inflate.out");
	int tott,m;
	int dp[10010];
	memset(dp,0,sizeof(dp));
	scanf("%d %d",&tott,&m);
	for(int i=0;i<m;i++)
	{
		int s,t;
		scanf("%d %d",&s,&t);
		for(int j=t;j<=tott;j++)
		{
			dp[j]=max(dp[j],dp[j-t]+s);
		}
	}
	printf("%d\n",dp[tott]);
    return 0;
}
