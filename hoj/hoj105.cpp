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
int A,B,C;
int N;
int p[5010];
void init()
{
	for(int i=0;i<=5000;i++)p[i]=i;
}
#define calc(x) (A*(x)*(x)+B*(x)+C)
inline int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b)
{
	p[find(a)]=find(b);
}
inline int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d",&N,&A,&B,&C);
		init();
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(find(i)==find(j))continue;
				if(gcd(calc(i),calc(j))==1)U(i,j);
			}
		}
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			if(find(i)==i)cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

