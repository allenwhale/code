#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
double to4(double a)
{
	double aa=a*1e4;
	aa+=0.5;
	int aaa=(int)aa;
	return (double)aaa/1e-4;
}
int main()
{
	double h,w;
	double k;
	while(1)
	{
		scanf("%lf %lf",&h,&w);
		if(h==w&&w==0)break;
		ll N,N_1,i;
		double lh=log10(h),lw=log10(w);
		if(w==1)N=1,N_1=2;				
		else
		{
			i=2;
			while(1)
			{
				if((int)h%(i+1)!=0||(int)w%i!=0)
				{
					i++;
					continue;
				}
				double t1=to4(lh/log10(i+1)),t2=to4(lw/log10(i));
				if(t1==t2)
				{
					N=i;
					N_1=i+1;
					break;
				}
				i++;
			}
		}
		ll high=0,nw=0;
		double t=(lh/log10(N_1));
		t=floor(t+0.5);
		for(i=0;i<=(ll)t;i++)
		{
			ll tmp1;
			tmp1=(h/(int)(pow(N_1,i)+0.5))*int(pow(N,i)+0.5);
			high+=tmp1;
			ll tmp2;
			tmp2=(int)(pow(N,i)+0.5);
			nw+=tmp2;
		}
		nw-=w;
		printf("%lld %lld\n",nw,high);
	}
    return 0;
}
