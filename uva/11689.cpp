#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int a,b,c;
		//printf("a");
		scanf("%d %d %d",&a,&b,&c);
		int all=a+b;
		int ans=0;
		while(all>=c)
		{
			int tmp=all/c;
			ans+=tmp;
			all=all-tmp*c+tmp;
		}
		printf("%d\n",ans);
	}
    return 0;
}
