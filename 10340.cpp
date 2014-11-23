#include <stdio.h>
#include <string.h>
char a[1000000],b[2000000];
int main()
{
	while(scanf("%s %s",a,b)!=EOF)
	{
		//printf("%s %s",a,b);
		int len=strlen(a);
		int l=strlen(b);
		if(len>l)
		{
			printf("No\n");
			continue;
		}
		int i,j=0;
		bool k;
		for(i=0;i<len;i++)
		{
			k=false;
			while(j<l)
			{
				if(a[i]==b[j])
				{
					k=true;
					j++;
					break;
				}
				j++;
				//if(j>=l)break;
			}
			if(k==false)break;
		}
		if(k)printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}
