#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==1)
		{
			printf("1 0\n1\n");
			continue;
		}
		printf("%d %d\n",n,n-1);
		int i;
		for(i=2;i<=n;i++)
		{
			printf("1 %d\n",i);
		}
		for(i=n;i>1;i--)
		{
			printf("%d ",i);
		}
		printf("1\n");
	}
    return 0;
}
