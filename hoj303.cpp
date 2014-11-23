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
int s[100010],ptr[100010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=N-1;i>=0;i--)
	{
		scanf("%d",&s[i]);
	}
	vector<int>vc;
	vc.PB(INF);
	for(int i=0;i<N;i++)
	{
		if(s[i]<vc.back())
		{
			ptr[i]=SIZE(vc);
			vc.PB(s[i]);
			continue;
		}
		int l=0,r=SIZE(vc);
		while(l+1!=r)
		{
			int mid=(l+r)>>1;
			if(vc[mid]<=s[i])r=mid;
			else l=mid;
		}
		vc[r]=s[i],ptr[i]=r;
	}
	int sz=SIZE(vc)-1;
	ll ans=0;
	for(int i=N-1;i>=0;i--)
	{
		if(ptr[i]==sz)
		{
			ans+=N-i;
			sz--;
		}
	}
	printf(__lld"\n",ans);
	return 0;
}

