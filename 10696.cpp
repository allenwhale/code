#include <stdio.h>
int f91(int n)
{
	if(n>100)return n-10;
	else return f91(f91(n+11));
}
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		printf("f91(%d) = %d\n",n,f91(n));
	}
    return 0;
}
