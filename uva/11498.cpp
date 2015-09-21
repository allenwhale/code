#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int i;
		for(i=1;i<=n;i++)
		{
			int xa,ya;
			scanf("%d %d",&xa,&ya);
			if(xa==x||ya==y)printf("divisa\n");
			else if(xa>x&&ya>y)printf("NE\n");
			else if(xa>x&&ya<y)printf("SE\n");
			else if(xa<x&&ya>y)printf("NO\n");
			else printf("SO\n");
		}
	}
    return 0;
}
