#include <stdio.h>
int main()
{
	int t;
	scanf("%d%*c",&t);
	char s[1000010];
	for(int i=0;i<t;i++)
	{
		gets(s);
		for(int i=0;s[i];i++)
		{
			if(('0'<=s[i]&&s[i]<='9')||('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
			{
				printf("%c",s[i]);
			}
		}
		puts("");
	}
	return 0;
}

