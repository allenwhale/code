#include <bits/stdc++.h>
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
int dp[10010];
int p[10010],k[10010];
int main()
{
	MS(dp,0);
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int mi;
		scanf("%d",&mi);
		for(int j=0;j<mi;j++)
		{
			scanf("%d %d",&p[j],&k[j]);
		}
		for(int j=N;j>=0;j--)
		{
			for(int q=0;q<mi;q++)
			{
				if(j-p[q]>=0)
					dp[j]=max(dp[j],dp[j-p[q]]+k[q]);
			}
		}
	}

	int ans=0;
	for(int i=0;i<=N;i++)
	{
		//printf("%d %d\n",i,dp[i][M]);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}

