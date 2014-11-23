#include <stdio.h>
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int m,d;
		scanf("%d %d",&m,&d);
		int j;
		int all=0;
		for(j=1;j<m;j++)
		{
			all+=day[j];
		}
		all+=(d-1);
		all+=6;
		int a=all%7;
		//printf("%s\n",date[all%7]);
		if(a==1)printf("Monday\n");
		else if(a==2)printf("Tuesday\n");
		else if(a==3)printf("Wednesday\n");
		else if(a==4)printf("Thursday\n");
		else if(a==5)printf("Friday\n");
		else if(a==6)printf("Saturday\n");
		else printf("Sunday\n");
	}
    return 0;
}
