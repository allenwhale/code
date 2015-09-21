#include <stdio.h>
#include <string.h>
int main()
{
	char n[1010];
	while(gets(n)!=NULL)
	{
		if(n[0]=='0'&&n[1]=='\0')break;
		int o1=0,o2=0;
		int len=strlen(n);
		int i;
		for(i=0;i<len;i++)
		{
			int k;
			char l[1];
			l[0]=n[i];
			sscanf(l,"%d",&k);
			if(i%2==0)o1+=k;
			else o2+=k;
		}
		printf("%s",n);
		if((o1-o2)%11==0)printf(" is a multiple of 11.\n");
		else printf(" is not a multiple of 11.\n");
	}
    return 0;
}
