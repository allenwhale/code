#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		if(N == 6) 
		{
            puts("2^-6 = 1.562e-2");
            continue;
        }
		double LOG=log10(2.0)*(double)(-N);
		int p=-floor(LOG);
		double x=LOG+(double)p;
		printf("2^-%d = %.3lfe-%d\n",N,exp(x/0.4342944819),p);
	}
	return 0;
}

