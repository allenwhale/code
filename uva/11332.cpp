#include <stdio.h>
int f(int s)
{
	int ans=0;
	if(s/10==0)return s;
	else 
	{
		
		while(s>0)
		{
			ans+=s%10;
			s=s/10;
		}
	}
	return f(ans);
}
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",f(n));
	}
    return 0;
}
