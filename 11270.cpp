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
ll dp[2][1024];
int main()
{
	int N,M;
	while(~scanf("%d %d",&N,&M))
	{
		if(N<M)swap(N,M);
		int flag=0;
		MS(dp,0);
		dp[0][(1<<M)-1]=1;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++,flag^=1)
			{
				MS(dp[flag^1],0);
				for(int k=0;k<(1<<M);k++)
				{
					int left,up;
					if(j==0)left=1;
					else left=k&(1<<(j-1));
					up=k&(1<<j);
					if(up==0)dp[flag^1][k|(1<<j)]+=dp[flag][k];
					if(left==0&&up!=0)dp[flag^1][k|(1<<j)|(1<<(j-1))]+=dp[flag][k];
					if(up!=0)dp[flag^1][k^(1<<j)]+=dp[flag][k];
				}
			}
		}
		printf(__lld"\n",dp[flag][(1<<M)-1]);
	}
	return 0;
}

