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
vector<int>vc[1000010];
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		int t;
		scanf("%d",&t);
		vc[t].PB(i);
	}
	scanf("%d",&N);
	while(N--)
	{
		int k;
		scanf("%d",&k);
		int p=1;
		bool tf=true;
		for(int i=0;i<k;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(!tf)continue;
			int ptr=lower_bound(vc[tmp].begin(),vc[tmp].end(),p)-vc[tmp].begin();
			if(ptr==SIZE(vc[tmp]))tf=false;
			else p=vc[tmp][ptr]+1;
		}
		if(tf)printf("TAK\n");
		else printf("NIE\n");
	}
	
	return 0;
}

