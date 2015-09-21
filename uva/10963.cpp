#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int t;
		scanf("%d",&t);
		int j;
		int ans,tmp;
		int a,b;
		scanf("%d %d",&a,&b);
		ans=a-b;
		bool y=true;
		for(j=1;j<t;j++)
		{
			scanf("%d %d",&a,&b);
			tmp=a-b;
			if(tmp!=ans)
			{
				y=false;
				break;
			}
		}
		if(i!=1)printf("\n");
		if(y)printf("yes\n");
		else printf("no\n");
	}
    return 0;
}
