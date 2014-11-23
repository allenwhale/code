#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MOD %=1000000007
using namespace std;
typedef long long ll;
ll dp[2][100010];
int pr[10000];
int cnt=0;
int main()
{
	pr[cnt++]=1;
	pr[cnt++]=2;
	for(int i=3;i<=100000;i+=2)
	{
		
		bool tf=true;
		for(int j=1;j<cnt&&pr[j]*pr[j]<=i&&tf;j++)
		{
			if(i%pr[j]==0)tf=false;
		}
		
		if(tf)pr[cnt]=i,cnt++;
	}
	//printf("%d\n",cnt);
	int t,m,n,s[60],all;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		all=0;
		memset(dp,0,sizeof(dp));
		//s[all++]=1;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			int index;
			scanf("%d",&index);
			//printf("%d %d\n",index,cnt);
			if(index>cnt)continue;
			//if(pr[index-1]>100000)continue;
			s[all++]=pr[index-1];
			//printf("%d\n",s[all-1]);
		}
		
		sort(s,s+all);
	//	printf("  %d\n",all);
	//	for(int j=0;j<all;j++)printf("%d ",s[j]);
	//	puts("");
		dp[0][0]=1;
		dp[1][0]=0;
		
		for(int j=1;j<=100009;j++)
		{
			ll win=0,lose=0;
			if(j<s[0])
			{
				dp[0][j]=1;
				dp[1][j]=0;
				continue;
			}
			for(int k=0;k<all&&s[k]<=j;k++)
			{
				win+=dp[0][j-s[k]] MOD;
				lose+=dp[1][j-s[k]] MOD;
			}
			if(win>0)
			{
				dp[0][j]=0;
				dp[1][j]=win MOD;
			}
			else
			{
				dp[0][j]=lose MOD;
				dp[1][j]=0;
			}
			//printf("%d %d ",j,dp[1][j]);
			//cprintf("%d\n",dp[0][j]);
		}
		int tt;
		scanf("%d",&tt);
		for(int j=0;j<tt;j++)
		{
			scanf("%d",&n);
			if(dp[1][n]>0)
			{
				printf("first %lld\n",dp[1][n]);
			}
			else 
			{
				printf("second %lld\n",dp[0][n]);
			}
		}
	}
	return 0;
}

