#include <stdio.h>
#include <string.h>
int main()
{
	int num=0;
	char a[20000];
	while(gets(a))
	{
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(a[i]=='"')
			{
				if(num%2==0)
				{
					printf("``");
				}
				else
				{
					printf("''");
				}
				num++;
			}
			else
			{
				printf("%c",a[i]);
			}
		}
		printf("\n");
	}
    return 0;
}
