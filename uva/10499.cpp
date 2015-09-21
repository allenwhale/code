#include <stdio.h>
int main()
{
	double n;
	while(~scanf("%lf",&n))
	{
		if(n<0)break;
		if(n==1)
		{
			printf("0%%\n");
			continue;
		}
		printf("%.0lf%%\n",n/4*100);
	}
    return 0;
}
