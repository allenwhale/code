#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int h,t,j,k,l,p,q,i;
	for(i=1;i<=n;i++)
	{		
		scanf("%d %d",&h,&t);
		for(j=1;j<=t;j++)
		{
			for(k=1;k<=h;k++)
			{
				for(l=1;l<=k;l++)
				{
					printf("%d",k);
				}
				printf("\n");
			}
			for(q=h-1;q>0;q--)
			{
				for(p=1;p<=q;p++)
				{
					printf("%d",q);
				}
				printf("\n");
			}
			if(!(i==n&&j==t)){printf("\n");}
		}
	}//while(1);
    return 0;
}
