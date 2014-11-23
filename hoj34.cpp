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
int main()
{
	stack<int>st;
	int N;
	scanf("%d",&N);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int tmp;
		scanf("%*d %d",&tmp);
		while(SIZE(st)>0&&st.top()>tmp)st.pop();
		if(SIZE(st)>0&&st.top()<tmp)
		{
			ans++;
			st.push(tmp);
		}
		if(SIZE(st)==0)
		{
			ans++;
			st.push(tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}

