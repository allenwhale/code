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
int dp[110][110];
int main()
{
	int W,H;
	while(~scanf("%d %d",&W,&H)&&W&&H)
	{
		MS(dp,0);
		//for(int i=0;i<=W;i++)dp[i][0]=1;
		//for(int i=0;i<=H;i++)dp[0][i]=1;
		//dp[0][0]=1;
		int N;
		scanf("%d",&N);
		while(N--)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			dp[a][b]=-1;
		}
		for(int i=0;i<=W;i++)
		{
			for(int j=0;j<=H;j++)
			{
				if(dp[i][j]==-1)dp[i][j]=0;
				else if(i==0&&j==0)dp[0][0]=1;
				else if(i==0)dp[0][j]=dp[0][j-1];
				else if(j==0)dp[i][0]=dp[i-1][0];
				else dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		if(dp[W][H]>1)printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",dp[W][H]);
		else if(dp[W][H]==0)printf("There is no path.\n");
		else printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
	}
	return 0;
}

