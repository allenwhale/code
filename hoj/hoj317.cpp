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
int N,W;
int w[100010];
int d[100010];
int main()
{
	scanf("%d %d",&N,&W);
	for(int i=0;i<W;i++)
	{
		scanf("%d",&w[i]);
	}
	sort(w,w+W);
	char s[100010];
	scanf("%s",s);
	d[0]=0;
	int p=0,mn=0,mx=0;
	for(int i=0;i<N-1;i++)
	{
		if(s[i]=='R')p++;
		else if(s[i]=='L')p--;
		mn=min(mn,p);
		mx=max(mx,p);
		d[i+1]=p;
	}
	if(mx-mn+1>W)puts("No");
	else 
		for(int i=0;i<N;i++)
			printf("%d\n",w[d[i]-mn]);
	return 0;
}

