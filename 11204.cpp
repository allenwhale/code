#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int m,s;
		scanf("%d %d",&m,&s);
		int j,k;
		int mm[40];
		for(j=1;j<=s;j++)
		{
			for(k=1;k<=m;k++)
			{
				int num;
				scanf("%d",&num);
				if(num==1)mm[k]++;
			}
		}
		int ans=0;
		for(j=1;j<=m;j++)
		{
			if(mm[j]!=0)ans=ans*mm[j];
		}
		printf("%d",ans);
	}
    return 0;
}
