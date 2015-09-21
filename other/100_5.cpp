#include <stdio.h>
int n[2][1000010]={-1};

int s[1000000];
int N=0;
int all;

int main()
{
	scanf("%d",&all);
	while(~scanf("%d",&s[N]))N++;
	n[1][0]=n[0][0]=-1;
	//int ans=dp(1,all);
	for(int i=1;i<=all;i++)
	{
		n[1][i]=n[0][i]=-1;
		for(int j=0;j<N&&i>=s[j];j++)
		{
			
			if(n[0][i]!=1)
			{
				if(n[1][i-s[j]]==-1)
				{
					n[0][i]=1;
				}
			}
			if(n[1][i]!=1)
			{
				if(n[0][i-s[j]]==-1)
				{
					n[1][i]=1;
				}
			}
		}
	}

	if(n[0][all]==1)
	{
		printf("A win\n");
	}
	else printf("B win\n");
	return 0;
}

