#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,num_1[3010],num_2[3010];
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&num_1[i]);
		}
		for(i=0;i<n-1;i++)
		{
			num_2[i]=abs(num_1[i]-num_1[i+1]);
		}
		sort(num_2,num_2+n-1);
		bool ans=true;
		for(i=0;i<n-1;i++)
		{
			if(num_2[i]!=i+1)
			{
				ans=false;
				break;
			}
		}
		if(ans)printf("Jolly\n");
		else printf("Not jolly\n");
	}
    return 0;
}
