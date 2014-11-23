#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		int j;
		int ans=0;
		for(j=a;j<=b;j++)
		{
			if(j%2==1)ans+=j;
		}
		printf("Case %d: %d\n",i,ans);
	}
    return 0;
}
