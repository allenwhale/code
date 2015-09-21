#include <stdio.h>
#include <string.h>
int main()
{
	char a[3000];
	while(gets(a)!=NULL)
	{
		int len=strlen(a);
		int i;
		int ans=0;
		char k=' ';
		for(i=0;i<len;i++)
		{
			if(((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))&&!((k>='A'&&k<='Z')||(k>='a'&&k<='z')))
			{
				ans++;
			}
			k=a[i];
		}
		printf("%d\n",ans);
	}
    return 0;
}

