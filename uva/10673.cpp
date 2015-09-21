#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int x,k;
		scanf("%d %d",&x,&k);
		printf("%d %d\n",k,k-k);
	}
    return 0;
}
