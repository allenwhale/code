#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int main()
{
	ll a,b,c;
	ll q;
	ll N;
	scanf("%lld",&N);
	for(q=1;q<=N;q++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case %lld: ",q);
		if(a<=0||b<=0||c<=0)
		{
			printf("Invalid\n");
			continue;
		}
		if(abs(a-b)<c&&abs(a-c)<b&&abs(c-b)<b&&a+b>c&&a+c>b&&c+b>a)
		{
			if(a==b&&b==c)
			{
				printf("Equilateral\n");
			}
			else if((a==b&&b!=c)||(a==c&&c!=b)||(c==b&&c!=a))
			{
				printf("Isosceles\n");
			}
			else
			{
				printf("Scalene\n");
			}
		}
		else 
		{
			printf("Invalid\n");
		}
	}
    return 0;
}
