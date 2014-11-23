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
#define A(x) (x)
#define B(x) (x+N)
#define C(x) (x+2*N)
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int p[50010*3];
void init()
{
	for(int i=0;i<50000*3+10;i++)p[i]=i;
}
int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b)
{
	p[find(a)]=find(b);
}
int N,K;
int main()
{
	scanf("%d %d",&N,&K);
	init();
	int ans=0;
	for(int i=0;i<K;i++)
	{
		int d,x,y;
		scanf("%d %d %d",&d,&x,&y);
		if(x>N||y>N)ans++;
		else if(d==1)
		{
			if(find(A(x))==find(B(y))||find(A(x))==find(C(y)))ans++;
			else U(A(x),A(y)),U(B(x),B(y)),U(C(x),C(y));
		}
		else if(d==2)
		{
			if(find(A(x))==find(A(y))||find(A(x))==find(B(y)))ans++;
			else U(B(x),A(y)),U(C(x),B(y)),U(A(x),C(y));
		}
	}
	printf("%d\n",ans);
	return 0;
}

