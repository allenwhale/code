#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int n[3];
		int j;
		for(j=0;j<3;j++)
		{
			scanf("%d",&n[j]);
		}
		sort(n,n+3);
		if(n[0]+n[1]>n[2])
		{
			printf("OK\n");
		}
		else 
		{
			printf("Wrong!!\n");
		}
	}
    return 0;
}
