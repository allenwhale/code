#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	int s[60];
	int k=0;
	while(~scanf("%d",&N)&&N)
	{
		k++;
		int i;
		int sum=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
			sum=sum+s[i];
		}
		int a=sum/N;
		sort(s,s+N);
		i=0;
		int ans=0;
		while(s[i]<a)
		{
			ans=ans+(a-s[i]);
			i++;
		}
		printf("Set #%d",k);
		printf("\nThe minimum number of moves is %d.\n\n",ans);
	}
    return 0;
}
