#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	int y[20];
	for(i=1;i<=N;i++)
	{
		int num;
		scanf("%d",&num);
		int j;
		for(j=0;j<num;j++)
		{
			scanf("%d",&y[j]);
		}
		printf("Case %d: ",i);
		sort(y,y+num);
		printf("%d\n",y[num/2]);
	}
    return 0;
}
