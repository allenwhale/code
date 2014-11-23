#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int N;
int s[2010];
int lis[2010],lds[2010];
void LIS()
{
	lis[N-1]=1;
	for(int i=N-2;i>=0;i--)
	{
		lis[i]=1;
		for(int j=i+1;j<N;j++)
		{
			if(s[j]>s[i])lis[i]=max(lis[i],lis[j]+1);
		}
	}
}
void LDS()
{
	lds[N-1]=1;
	for(int i=N-2;i>=0;i--)
	{
		lds[i]=1;
		for(int j=i+1;j<N;j++)
		{
			if(s[j]<s[i])lds[i]=max(lds[i],lds[j]+1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
		}
		LIS();LDS();

		int ans=0;
		for(int i=0;i<N;i++)
		{
			ans=max(ans,lis[i]+lds[i]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
