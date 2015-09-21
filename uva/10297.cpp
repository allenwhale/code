#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int main()
{
	const double PI=2.0*acos(0);
	double D,V;
	while(~scanf("%lf %lf",&D,&V)&&D)
	{
		printf("%.3lf\n",pow((D*D*D-V*6.0/PI),1.0/3.0));
	}
	return 0;
}

