#include <stdio.h>
int num;
int f(int n)
{
	num++;
	if(n==1)return num;
	if(n%2==0)
	{
		f(n/2);
	}
	else
	{
		f(3*n+1);
	}	
}
int main()
{
	int n,m;
	int a,b;
	int temp;
	int i;
	while(~scanf("%d %d",&a,&b))
	{
		int ans=0;
		if(a>b)
		{
			n=b;
			m=a;	
		}
		else
		{
			n=a;
			m=b; 
		}
		for(i=n;i<=m;i++)
		{
			num=0;
			temp=f(i);
			if(temp>ans)
			{
				ans=temp;
			}
		}
		printf("%d %d %d\n",a,b,ans);	
	}
    return 0;
}
