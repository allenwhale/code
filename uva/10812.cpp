#include <stdio.h>
bool integer(float s)
{
	if(s-(int)s==0)return true;
	return false;
}
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		double s,d;
		scanf("%lf %lf",&s,&d);
		double a,b;
		a=(s+d)/2;
		b=s-a;
		if(integer(a)&&integer(b)&&a>=0&&b>=0)printf("%.0lf %.0lf\n",a,b);
		else printf("impossible\n");
	}
    return 0;
}
