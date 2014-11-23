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

int main()
{
	int N;
	while(~scanf("%d",&N)&&N)
	{
		stack<pI>st;
		st.push(MP(-1,0));
		ll ans=0ll;
		for(int i=0;i<=N;i++)
		{
			int high;
			if(i<N)scanf("%d",&high);
			else high=0;
			pI tmp=MP(high,i);
			while(st.top().FF>high)
			{
				tmp=st.top();st.pop();
				//printf("%d %d %d\n",tmp.SS,i,high);
				ans=max(ans,(ll)(i-tmp.SS)*tmp.FF); 
			}
			if(high>st.top().FF)st.push(MP(high,tmp.SS));
		}
		printf(__lld"\n",ans);
	}
	return 0;
}

