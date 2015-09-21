#include <stdio.h>
int main()
{
	int n,m,i,j,add=0,ans=0;
	while(1)
	{
		add=0;
		ans=0;
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)break;
		while(1)
		{
			i=n%10;
			j=m%10;
			//printf("\t\t%d %d\n",i,j);
			add=add+i+j;
			if(add>=10)
			{
				ans++;	
			}
			add=add/10;
			n=n/10;
			m=m/10;
			//printf("\t%d %d\n",n,m);
			if(n==0&&m==0)break;
		}
		if(ans==0)
		{
			printf("No carry operation.\n");
		}
		else if(ans==1)
		{
			printf("1 carry operation.\n");
		}
		else
		{
			printf("%d carry operations.\n",ans);
		}
	}
    return 0;
}
