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
#define PF(a) push_front(a)
#define PPF() pop_front()
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
int dp[100010*2];
bool ok[100010*2];
int *DP=dp+100001;
bool *OK=ok+100001;
int main()
{
	MS(ok,false);
	fill(dp,dp+100010*2,-INF);
	DP[0]=0;
	OK[0]=true;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int S,F;
		scanf("%d %d",&S,&F);
		if(S>=0)
		{
			for(int j=100000;j>=-100000;j--)
			{
				int jj=j-S;
				if(jj<-100000)break;
				if(OK[jj]==false)continue;
				OK[j]=true;
				DP[j]=max(DP[j],DP[jj]+F);
			}
		}
		else
		{
			for(int j=-100000;j<=100000;j++)
			{
				int jj=j-S;
				if(jj>100000)break;
				if(OK[jj]==false)continue;
				OK[j]=true;
				DP[j]=max(DP[j],DP[jj]+F);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=100000;i++)
		if(OK[i]&&DP[i]>=0)ans=max(ans,i+DP[i]);
	printf("%d\n",ans);
	return 0;
}

