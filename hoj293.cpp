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
#include <time.h>
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
vector<int>vc[100010];
int N,M;
int p[100010];
int main()
{
	srand(clock());
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].PB(b);
		vc[b].PB(a);
	}
	for(int i=0;i<N;i++)p[i]=i+1;
	for(int i=0;i<40;i++)
	{
		random_shuffle(p,p+N);
		bool tf=true;
		for(int j=0;j<M;j++)
		{
			int a=p[j];
			int b=p[(j+1)%N];
			foreach(it,vc[a])
			{
				//printf("  %d %d\n",a,*it);
				if(*it==b)tf=false;
			}
		}
		if(!tf)continue;
		for(int j=0;j<M;j++)
		{
			int a=p[j];
			int b=p[(j+1)%N];
			printf("%d %d\n",a,b);
		}
		return 0;
	}
	puts("-1");
	return 0;
}

