#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		double num;
		scanf("%lf",&num);
		double s[1010];
		int j;
		double avg,sum=0;
		for(j=0;j<num;j++)
		{
			scanf("%lf",&s[j]);
			sum+=s[j];
		}
		avg=sum/num;
		double high=0;
		for(int k=0;k<num;k++)
		{
			if(s[k]>avg)high++;
		}
		printf("%.3lf",high/num*100);
		printf("%%\n");
	}
    return 0;
}
