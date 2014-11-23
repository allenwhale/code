#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		
		double by,bm,bd,ny,nm,nd;
		scanf("%lf/%lf/%lf",&nd,&nm,&ny);
		scanf("%lf/%lf/%lf",&bd,&bm,&by);
		double bri,now;
		bri=by+(bm-1)/12+(bd-1)/360;
		now=ny+(nm-1)/12+(nd-1)/360;
		printf("Case #%d: ",i);
		if(now<bri)
		{
			printf("Invalid birth date\n");
			continue;
		}
		else if(now-bri>=130)
		{
			printf("Check birth date\n");
			continue;
		}
		else
		{
			printf("%d\n",(int)(now-bri));
		}
	}//while(1);
    return 0;
}
