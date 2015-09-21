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
		int n;
		scanf("%d",&n);
		int j;
		int p[20010];
		int ans=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[j]);
		}
		sort(p,p+n);
		
		int k=1;
		for(j=n-1;j>=0;j--)
		{
			if(k%3==0)ans+=p[j];
			k++;
		}
		printf("%d\n",ans);
	}
    return 0;
}
