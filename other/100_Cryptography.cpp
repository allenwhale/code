#include <stdio.h>
int main()
{
	int N[3010],M[3010];
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int j=0;j<n/2;j++)
		{
			scanf("%2X",&N[j]);
		}
		for(int j=0;j<m/2;j++)
		{
			scanf("%2x",&M[j]);
		}
		for(int j=0;j<n/2;j++)
		{
			N[j]^=M[j];
		}
		for(int j=0;j<n/2;j++)
		{
			printf("%02X",N[j]);
		}
		puts("");
	}

	return 0;
}

