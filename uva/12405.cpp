#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	char s[110];
	for(i=1;i<=N;i++)
	{
		int n;
		scanf("%d",&n);
		getchar();
		gets(s);
		printf("Case %d: ",i);
		int j;
		int ans=0;
		for(j=0;j<n;j++)
		{
			if(s[j]=='#')continue;
			ans++;
			j=j+2;
		}
		printf("%d\n",ans);
	} 
    return 0;
}
