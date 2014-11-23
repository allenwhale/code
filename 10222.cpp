#include <stdio.h>
#include <string.h>
char fr[]="23edc4rfv5tgb6yhn7ujm8ik,9ol.0p;/-[\'=]\\ ";
char to[]="`1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol0p[ ";
int find(char s)
{
	int i;
	for(i=0;i<45;i++)
	{
		if(s==fr[i])return i;
	}
}
int main()
{
	char k[1000];
	while(gets(k)!=NULL)
	{
		int len=strlen(k);
		for(int i=0;i<len;i++)
		{
			printf("%c",to[find(k[i])]);
		}
		printf("\n");
	}
    return 0;
}
