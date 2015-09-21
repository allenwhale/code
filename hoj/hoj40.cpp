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
ll dp[10010];
int s[30];
int main()
{
	int N,V;
	scanf("%d %d",&V,&N);
	for(int i=0;i<V;i++)
		scanf("%d",&s[i]);
	MS(dp,0ll);
	dp[0]=1;
	for(int i=0;i<V;i++)
	{
		for(int j=s[i];j<=N;j++)
		{
			dp[j]+=dp[j-s[i]];
		}
	}
	printf(__lld"\n",dp[N]);
	return 0;
}

