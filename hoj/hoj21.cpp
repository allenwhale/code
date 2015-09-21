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
int N;
int w[1000010];
int A[1000010],B[1000010];
int PA[1000010],PB[1000010];
bool f[1000010];
int main()
{
	int mn=1e9;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&w[i]),mn=min(mn,w[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]),PA[A[i]]=i;
	for(int i=0;i<N;i++)
		scanf("%d",&B[i]),PB[B[i]]=i;
	ll ans=0;
	for(int i=0;i<N;i++)
	{
		ll small=w[A[i]],sum=w[A[i]],cnt=1;
		while(A[i]!=B[i])
		{
			int ptr=PB[A[i]];
			sum+=w[A[ptr]],small=min(small,(ll)w[A[ptr]]);
			cnt++;
			swap(A[i],A[ptr]);
		}
		ans+=sum+min(small*(ll)(cnt-2),small+(ll)(cnt+1)*mn);
	}
	printf(__lld"\n",ans);
	return 0;
}

