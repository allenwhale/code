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
char s[1000010];
bool ss[1000010];
int N;
int main()
{	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		scanf("%s",s);
		for(int i=0;i<N;i++)
			if(s[i]=='A')ss[i]=true;
			else ss[i]=false;
		bool tf=true;
		int cnt=0;
		for(int i=N-1;i>=0;i--)
		{
			//printf("%d %d\n",tf,ss[i]);
			if(ss[i]==tf);
			else
			{
				if(i==0||ss[i-1]==tf)cnt++;
				else cnt++,tf^=true;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

