#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	printf("Lumberjacks:\n");
	for(i=1;i<=N;i++)
	{
		int l[10];
		int j;
		for(j=0;j<10;j++)
		{
			scanf("%d",&l[j]);
		}
		bool ans=true;
		for(j=0;j<9;j++)
		{
			if(l[j]<l[j+1])ans=false;
		}
		if(ans)
		{
			printf("Ordered\n");
			continue;;
		}
		ans=true;
		for(j=0;j<9;j++)
		{
			if(l[j]>l[j+1])ans=false;
		}
		if(ans)
		{
			printf("Ordered\n");
			continue;
		}
		printf("Unordered\n");
	}
    return 0;
}
