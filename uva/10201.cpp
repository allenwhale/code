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
int N,dp[110][210],d[110],p[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%*c",&N);
		char tmp[110];
		d[0]=0;
		int cnt=0;
		d[cnt++]=0;
		while(gets(tmp)!=NULL&&tmp[0])
		{
			sscanf(tmp,"%d %d",&d[cnt],&p[cnt]);
			cnt++;
		}
		d[cnt]=N;
		MS(dp,0x3f);
		dp[0][100]=0;
		for(int i=1;i<=cnt;i++)
		{
			//printf(" %d %d\n",d[i],p[i]);
			int dis=d[i]-d[i-1];
			for(int j=dis;j<=200;j++)
				dp[i][j-dis]=dp[i-1][j];
			if(i!=cnt)for(int j=1;j<=200;j++)
				dp[i][j]=min(dp[i][j],dp[i][j-1]+p[i]);
		}
		int ans=INF;
		for(int i=100;i<=200;i++)
			ans=min(ans,dp[cnt][i]);
		if(ans==INF)printf("Impossible\n");
		else printf("%d\n",ans);
		if(T)puts("");
	}
	return 0;
}

