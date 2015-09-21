#include <stdio.h>
#include <string.h>
int main()
{
	int n,m;
	int s;
	bool iphone[110];
	memset(iphone,true,sizeof(iphone));
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&s);
		for(int j=1;j*s<=n;j++)
		{
			iphone[j*s]=!iphone[j*s];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=iphone[i]?0:1;
	}
	printf("%d\n",cnt);
	return 0;
}

