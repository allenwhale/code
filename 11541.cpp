#include <stdio.h>
int toi(char s)
{
	return s-'0';
}
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	char s[100];
	getchar();
	for(i=1;i<=N;i++)
	{
		gets(s);
		printf("Case %d: ",i);
		int j=0;
		while(s[j]!='\0')
		{
			int t=0;
			char ts=s[j];
			j++;
			while(toi(s[j])<=9&&toi(s[j])>=0)
			{
				t=t*10+toi(s[j]);
				j++;
			}
			int k;
			for(k=1;k<=t;k++)
			{
				printf("%c",ts);
			}
		}
		printf("\n");
	}
    return 0;
}
