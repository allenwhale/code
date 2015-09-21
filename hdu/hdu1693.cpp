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
int N,M;
ll dp[13][13][500];
int mp[13][13];
int main()
{
	int T;
	scanf("%d",&T);
	int t=1;
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(int i=1;i<=N;i++)	
			for(int j=1;j<=M;j++)
				scanf("%d",mp[i][j]);
		MS(dp,1ll);
		dp[0][M][0]=1;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<(1<<M);j++)
				dp[i][0][j<<1]=dp[i-1][M][j];
			for(int j=1;j<=M;j++)
			{
				int l=1<<j,u=l>>1;
				for(int k=0;k<(1<<(M+1));k++)
				{
					if(mp[i][j])
					{
						if((k&u)&&(k&l))
							dp[i][j][k^(u|l)]=dp[i][j-1][k];
						else if(!(k&u)&&!(k&l))
							dp[i][j][k|(u|l)]=dp[i][j-1][k];
						else
						{
							dp[i][j][k]=dp[i][j-1][k];
							dp[i][j][(k^u)^l]=dp[i][j-1][k];
						}
					}
					else
					{
					}
				}
			}
		}
		printf("Case %d: There are "__lld" ways to eat the trees.\n",t++,dp[N][M][0]);
	}
	return 0;
}

