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
int N,C;
int s[100010];
bool check(int x)
{
	int n=C,last=-INF;
	for(int i=0;i<N&&n;i++)
	{
		if(s[i]-last>=x)last=s[i],n--;
	}
	//printf("%d %d\n",x,n);
	return n==0;
}
int main()
{
	scanf("%d %d",&N,&C);
	for(int i=0;i<N;i++)
		scanf("%d",&s[i]);
	sort(s,s+N);
	//for(int i=0;i<N;i++)printf("%d\n",s[i]);
	int l=0,r=s[N-1];
	int ans=-1;
	while(l<=r)
	{
		
		int mid=(l+r)>>1;
		//printf("  %d\n",mid);
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

