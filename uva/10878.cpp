#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	char s[20];
	int i;
	gets(s);
	while(1)
	{
		gets(s);
		if(s[0]=='_')break;
		int k=0,ans=0;
		for(i=9;i>0;i--)
		{
			if(s[i]=='o')ans+=pow(2,k);
			if(s[i]=='.')continue;
			k++;
		}
		printf("%c",ans);
	}
    return 0;
}
