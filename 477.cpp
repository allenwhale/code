#include <stdio.h>
int main()
{
	char s;
	int i=0;
	float a[12][7];
	while(1)
	{
		scanf("%c",&s);
		if(s=='*')break;
		if(s=='r')
		{
			a[i][0]=0;
			scanf("%f %f %f %f",&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
			a[i][1]=i+1;
		}
		if(s=='c')
		{
			a[i][0]=1;
			scanf("%f %f %f",&a[i][2],&a[i][3],&a[i][4]);
			a[i][1]=i+1;
		}
		i++;
		getchar();
	}
	double x,y;
	int num=1;
		while(1)
	{
		int ans=0;
		scanf("%lf %lf",&x,&y);
		if(x==y && x==9999.9)
		{
			return 0;
		}
		for(int j=0;j<=i;j++)
		{
			if(a[j][0]==0)
			{
				if(x>a[j][2]&&x<a[j][4]&&y>a[j][5]&&y<a[j][3])
				{
					printf("Point %d is contained in figure %d\n",num,j+1);
					ans=1;
				}
			}
			if(a[j][0]==1)
			{
				if((x-a[j][2])*(x-a[j][2])+(y-a[j][3])*(y-a[j][3])<a[j][4]*a[j][4])
				{
					printf("Point %d is contained in figure %d\n",num,j+1);
					ans=1;	
				}
			}
		}
		if(ans==0)
		{
			printf("Point %d is not contained in any figure\n",num);
		}
		num++;
	}
    return 0;
}
