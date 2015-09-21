#include <stdio.h>
#include <math.h>
int main()
{
	double a,b;
	while(~scanf("%lf %lf",&a,&b))
	{
		double t=pow(b,1/a);
		long long tt=(long long)(t+0.5);
		printf("%lld\n",tt);
	}
    return 0;
}
