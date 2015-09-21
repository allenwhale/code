#include <math.h>
#include <stdio.h>
#include <string.h>
int main()
{
	while(1)
	{
		float hr,min;
		scanf("%f:%f",&hr,&min);
		if(hr==min&&min==0)break;
		float dh,dm;
		dh=hr*30+min/2;
		dm=6*min;
		float dd;
		dd=fabs(dm-dh);
		if(dd>180)dd=360-dd;
		printf("%.3f\n",dd);
	}
    return 0;
}
