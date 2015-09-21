b#include <stdio.h>
int s[300];
int main()
{
	int i;
	int n;
	for(scanf("%d",&n))
	{
		if(n==0)break;
		int j,k;
		for(j=0;j<n;j++)
		{
			scanf("%d",&s[j]);
		}
		bool tf=true;
		for(j=0;j<n&&tf;j++)
		{
			if(s[j]+j>=n)
			{
				tf=false;
				break;
			}
			int l=s[j];
			s[j]=0;
			for(k=j+1;k<=j+l;k++)
			{
				if(--s[k]<0)
				{
					tf=false;
					break;
				}
			}
		}
		if(tf)printf("Possible\n");
		else printf("Not possible\n");
	}
    return 0;
}
