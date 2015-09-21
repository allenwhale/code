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
#include "interactive/118.h"
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
int x[110],y[110];
vector<int>vc;
int main()
{
	int N=Init();
	MS(x,0);
	for(int i=1;i<=N;i++)vc.PB(i);
	for(int i=1;i<=N;i++)
	{
		int l=1,r=N+1;
		while(l+1<=r)
		{
			int mid=(l+r)>>1;
			MS(y,0);
			for(int j=l;j<=mid;j++)
				y[j]=i;
			if(Answer(y)==1)r=mid;
			else l=mid+1;
		}
		x[r]=i;
	}
	Answer(x);
	return 0;
}

