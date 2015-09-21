#include <stdio.h>
int one(char s[])
{
	int a=0;
	int i=0;
	char ss[]="one";
	while(s[i]!='\0')
	{
		if(ss[i]!=s[i])a++;
		i++;
	}
	return a;
}
int two(char s[])
{
	int a=0;
	int i=0;
	char ss[]="two";
	while(s[i]!='\0')
	{
		if(ss[i]!=s[i])a++;
		i++;
	}
	return a;
}
int three(char s[])
{
	int a=0;
	int i=0;
	char ss[]="three";
	while(s[i]!='\0')
	{
		if(ss[i]!=s[i])a++;
		i++;
	}
	return a;
}
int main()
{
	int N;
	scanf("%d",&N);
	int i;
	getchar();
	char s[10];
	for(i=1;i<=N;i++)
	{
		gets(s);
//		printf("%s",s);
		if(one(s)==1||one(s)==0)
		{
			printf("1\n");
			continue;
		}
		if(two(s)==1||two(s)==0)
		{
			printf("2\n");
			continue;
		}
		if(three(s)==1||three(s)==0)
		{
			printf("3\n");
			continue;
		}
		
	}
    return 0;
}
