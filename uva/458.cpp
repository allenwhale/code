#include <stdio.h>
#include <string.h>
int main()
{
	char a[10000];
	while(gets(a))
	{
		int i;
		for(i=0;i<strlen(a);i++)
		{
			printf("%c",(char)(((int)a[i])-7));
		}
		printf("\n");
	}
    return 0;
}
