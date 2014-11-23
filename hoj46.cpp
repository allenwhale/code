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
int N;
int r[1010],c[1010];
ll dp[1010][1010];
ll dfs(int a,int b)
{
	ll &tmp=dp[a][b];
	if(tmp!=-1ll)return tmp;
	if(a==b)return tmp=0ll;
	tmp=(ll)INF*(ll)INF;
	for(int i=a;i<b;i++)
	{
		tmp=min(tmp,dfs(a,i)+dfs(i+1,b)+r[a]*c[i]*c[b]);
	}
	//printf("%d %d %d\n",a,b,tmp);
	return tmp;
}
int main()
{
	int T;
	scanf("%d",&T);
	ll sum=0;
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&r[i],&c[i]);
		}
		MS(dp,-1ll);
		ll ans=dfs(0,N-1);
		//printf("  %d\n",ans);
		if(ans%1000ll==0ll)printf(__lld"\n",ans/1000ll),sum+=ans;
		else printf(__lld"\n",ans/1000ll+1ll),sum+=ans;
	}
	if(sum%1000==0)printf(__lld"\n",sum/1000ll);
	else printf(__lld"\n",sum/1000ll+1ll);
	return 0;
}

