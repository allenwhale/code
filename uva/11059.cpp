typedef long long ll;
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	ll dp[20][20];
	int N;
	int q=0;
	while(~scanf("%d",&N))
	{
		q++;
		int s[20];
		int i,j;
		for(i=1;i<=N;i++)
		{
			scanf("%lld",&s[i]);
		}
		for(i=0;i<=N;i++)
		{
			for(j=0;j<=N;j++)
			{
				dp[i][j]=1;
			}
		}
		ll mx=-1;
		for(i=1;i<=N;i++)
		{
			for(j=i;j<=N;j++)
			{
				dp[i][j]=dp[i][j-1]*s[j];
				mx=max(dp[i][j],mx);
			}
		}
	
		if(mx<0)printf("Case #%d: The maximum product is 0.\n",q);
		else printf("Case #%d: The maximum product is %lld.\n",q,mx);
		printf("\n");	
	}
    return 0;
}
