#include <stdio.h>
#include <string.h>
int D[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		int d,n;
		long long sum=0;
		scanf("%d %d",&d,&n);
		memset(D,0,sizeof(D[0])*d);
		D[0]=1;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			sum+=(long long)x;
			sum%=(long long)d;
			D[(int)sum]++;
		}
		long long ans=0;
		for(int i=0;i<d;i++)
		{
			ans+=(long long)D[i]*(D[i]-1)/2;
		}
		printf("%d\n",ans);
	}
	return 0;
}

