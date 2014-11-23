#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++)
	{
		int f,ans=0;
		scanf("%d",&f);
		for(j=1;j<=f;j++)
		{
			//printf("\t%d\n",j);
			int p,a,e;
			scanf("%d %d %d",&p,&a,&e);
			ans+=p*e;
		}
		printf("%d\n",ans);
	}
    return 0;
}
