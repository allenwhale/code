#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			printf(">\n");
		}
		else if(a<b)
		{
			printf("<\n");
		}
		else
		{
			printf("=\n");
		}
	}
    return 0;
}
