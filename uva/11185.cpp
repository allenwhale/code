#include <stdio.h>
int main()
{
	int n;
	int n_3[1000];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if(n<0)break;
		int i=0;
		while(n>0)
		{
			n_3[i]=n%3;
			n=n/3;
			i++;
		}
		for(int j=i-1;j>=0;j--)
		{
			printf("%d",n_3[j]);
		}
		printf("\n");
	}
    return 0;
}
