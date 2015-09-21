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
int s[1000005];
int r[1000005];
ll sum[1000005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		MS(r,0);
		MS(sum,0);
		int N,a,b,c;
		scanf("%d %d %d %d %d",&N,&a,&b,&c,&s[1]);
		if(N==1)
		{
			printf("0\n");
			continue;
		}
		ll ans=s[1];
		r[s[1]]=1;
		sum[1]=s[1];
		int st=0,ed=0,len;
		int mx=s[1];
		for(int i=2;i<=N;i++)
		{
			ll tmp=((ll)s[i-1]*(ll)a+(ll)b)%(ll)c;
			s[i]=tmp;
			if(r[s[i]])
			{
				st=r[s[i]];
				ed=i-1;
				len=ed-st+1;
				break;
			}
			mx=max(mx,s[i]);
			r[s[i]]=i;
			sum[i]=sum[i-1]+(ll)s[i];
			ans+=(ll)s[i];
		}
		if(st&&ed)
		{
			int cnt=(N-(st-1))/len;
			ans+=(ll)(cnt-1)*(ll)(sum[ed]-sum[st-1]);
			int left=N-(st-1)-len*cnt;
			ans+=(sum[st+left-1]-sum[st-1]);
		}
		ans+=(ll)(N-2)*(ll)mx;
		printf(__lld"\n",ans);
	}
	return 0;
}

