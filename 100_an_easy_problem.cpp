#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		ll s[4];
		scanf("%lld%lld%lld",&s[0],&s[1],&s[2]);
		sort(s,s+3);
		if((s[0]<=0||s[1]<=0||s[2]<=0)||s[0]+s[1]<=s[2])
		{
			printf("illegal triangle\n");
		}
		else if(s[0]*s[0]+s[1]*s[1]==s[2]*s[2])
		{
			printf("right triangle\n");
		}
		else if(s[0]*s[0]+s[1]*s[1]<s[2]*s[2])
		{
			printf("acute triangle\n");
		}
		else if(s[0]*s[0]+s[1]*s[1]>s[2]*s[2])
		{
			printf("obtuse triangle\n");
		}
	}
	return 0;
}

