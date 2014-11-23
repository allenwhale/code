#include <stdio.h>
#include <math.h>
bool find(double sx,double sy,double a)
{
	double q=sqrt(sx*sx+sy*sy);
	double w=sqrt(sx*sx+(sy-a)*(sy-a));
	double e=sqrt((sx-a)*(sx-a)+sy*sy);
	double r=sqrt((sx-a)*(sx-a)+(sy-a)*(sy-a));
	if(q<=a&&w<=a&&e<=a&&r<=a)return true;
	return false;
}
int main()
{
	int N,i;
	double a;
	while(1)
	{
		scanf("%d %lf",&N,&a);
		if(N==0)break;
		int ans=0;
		for(i=1;i<=N;i++)
		{
			double x,y;
			scanf("%lf %lf",&x,&y);
			if(find(x,y,a))ans++;
		}
		//printf("%d",ans);
		double area=a*a*((double)ans/(double)N);
		printf("%.5lf\n",area);
	}
	
    return 0;
}
