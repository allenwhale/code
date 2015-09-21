typedef long long ll;
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	ll num[20000];
	int i=0;
	while(~scanf("%lld",&num[i]))
	{
		sort(num,num+i+1);
		if(i%2==0)
		{
			printf("%lld\n",num[i/2]);
		}
		else
		{
			ll a=num[(i+1)/2];
			ll b=num[(i+1)/2-1];
			//printf("\t%d\n",a+b);
			printf("%lld\n",(a+b)/2);
		}
		i++;
	}
    return 0;
}
