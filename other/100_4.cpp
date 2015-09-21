#include <stdio.h>
int c[3];
int t[3];
int now;
int main()
{
	while(1)
	{
		scanf("%d",&now);
		for(int i=0;i<3;i++)
		{
			scanf("%d",&c[i]);
		}
		if(now==0&&c[0]==0&&c[1]==0&&c[2]==0)break;
	//	t[0]=(c[0]-now+40)%40;
	//	t[1]=(c[1]-c[0]+40)%40;
	//	t[3]=(c[2]-c[1]+40)%40;
		if(c[0]<now)
		{
			t[0]=40-(now-c[0]);
		}
		else
		{
			t[0]=c[0]-now;
		}
		
		if(c[1]<c[0])
		{
			t[1]=c[0]-c[1];
		}
		else
		{
			t[1]=40-(c[1]-c[0]);
		}
		
		if(c[2]<c[1])
		{
			t[2]=40-(c[2]-c[1]);
		}
		else
		{
			t[2]=c[2]-c[1];
		}
	//	t[0]=(-c[0]+now+40)%40;
	//	t[1]=(-c[1]+c[0]+40)%40;
	//	t[3]=(+c[2]-c[1]+40)%40;
		t[0]=(40-t[0]);
		t[1]=(40-t[1]);
		t[2]=(40-t[2]);
		int all=t[0]+t[1]+t[2]+120;
		//printf("%d %d %d\n",t[0],t[1],t[2]);
		double ans=(360.0/40.0)*(double)all;
		printf("%lf\n",ans);
	}
	return 0;
}

