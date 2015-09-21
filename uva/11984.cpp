#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);;
	int i;
	for(i=1;i<=N;i++)
	{
		double c,d;
		scanf("%lf %lf",&c,&d);
		printf("Case %d: ",i);
		double ans=c+d*5/9;
		printf("%.2lf\n",ans);
	}
    return 0;
}
