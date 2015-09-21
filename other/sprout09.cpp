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
int sum[4010];
int cnt[36010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		MS(cnt,0);
		int N;
		scanf("%d%*c",&N);
		char s[40010];
		gets(s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			sum[i]=sum[i-1]+s[i]-'0';
		}
		for(int i=1;i<=len;i++)
		{
			for(int j=i;j<=len;j++)
			{
				cnt[sum[j]-sum[i-1]]++;
			}
		}
		ll ans=0ll;
		int a=N;
		if(a==0)
		{
			for(int i=1;i<=36000&&i<=sum[len];i++)
				ans+=2ll*(ll)cnt[0]*cnt[i];
			ans+=(ll)cnt[0]*cnt[0];
		}
		else
		{
			for(int i=1;i<=a&&i<=36000;i++)
			{
				if(cnt[i]>0&&a%i==0&&(a/i)<=36000&&cnt[a/i]>0)
					ans+=(ll)cnt[i]*cnt[a/i];
			}
		}
		printf(__lld"\n",ans);
	}
	return 0;
}
