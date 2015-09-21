#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int n;
		scanf("%d",&n);
		int j;
		int mx=-1,mn=9999;
		for(j=1;j<=n;j++)
		{
			int d;
			scanf("%d",&d);
			if(d>mx)mx=d;
			if(d<mn)mn=d;
		}
		printf("%d\n",(mx-mn)*2);
	}
    return 0;
}
