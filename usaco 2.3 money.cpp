/*
ID: allenwh1
PROG: money
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
typedef long long ll;
ll dp[10010];
int main()
{
	fin("money.in");
	fout("money.out");
	int v,c;
	scanf("%d %d",&v,&c);
	int V[30];
	for(int i=0;i<v;i++)
	{
		scanf("%d",&V[i]);
	}
	sort(V,V+v);
	dp[0]=1;
	for(int i=0;i<v;i++)
	{
		for(int j=V[i];j<=c;j++)
		{
			dp[j]+=dp[j-V[i]];
		}
	}
	printf("%lld\n",dp[c]);
    return 0;
}
