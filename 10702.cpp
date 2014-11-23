#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PPF(a) push_front(a)
#define PF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int C,S,E,T;
int mp[110][110];
int dp[1100][110];

int main()
{
	while(~scanf("%d %d %d %d",&C,&S,&E,&T)&&C)
	{
		for(int i=1;i<=C;i++)
		{
			for(int j=1;j<=C;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		MS(dp,-1);
		dp[0][S]=0;
		for(int i=0;i<T;i++)
		{
			for(int j=1;j<=C;j++)
			{
				if(dp[i][j]==-1)continue;
				for(int k=1;k<=C;k++)
				{
					if(j!=k&&dp[i+1][k]<dp[i][j]+mp[j][k])
					{
						dp[i+1][k]=dp[i][j]+mp[j][k];
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<E;i++)
		{
			int e;
			scanf("%d",&e);
			ans=max(ans,dp[T][e]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

