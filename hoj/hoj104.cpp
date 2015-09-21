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
int N,M,P;
struct E
{
	int a,b,c;
}e[10010];
int d[110];
bool tf;
void BF()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(d[e[j].a]>d[e[j].b]+e[j].c)
			{
				d[e[j].a]=d[e[j].b]+e[j].c;
				tf=true;
			}
		}
	}
}
void neg()
{
	BF();
	tf=false;
	BF();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N,&M,&P);
		for(int i=0;i<M;i++)
		{
			int a,b;
			scanf("%d %d %d %d",&e[i].a,&e[i].b,&a,&b);
			e[i].c=b*P-a;
		}
		MS(d,0x3f);
		d[1]=0;
		neg();
		if(tf)puts("Yes");
		else puts("No");
	}
	return 0;
}

