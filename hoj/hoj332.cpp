#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
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
int w[500010];
vector<ll>vc[500010];
ll ans[500010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&w[i]);
		for(int j=0;j<w[i];j++)
		{
			ll idx;
			scanf(__lld,&idx);
			vc[i].PB(idx);
		}
	}
	w[N]=0;
	sort(w,w+N+1);
	int sz=unique(w,w+N+1)-w;
	fill(ans,ans+sz+1,(ll)-INF*INF);
	for(int i=0;i<N;i++)
	{
		//printf("%d\n",i);
		for(int j=0;j+1<sz&&w[j+1]<=SIZE(vc[i]);j++)
		{
			ans[j]=max(ans[j],accumulate(vc[i].begin()+w[j],vc[i].begin()+w[j+1],0ll));
		}
	}
	partial_sum(ans,ans+sz-1,ans);
	printf(__lld"\n",*max_element(ans,ans+sz-1));
	return 0;
}

