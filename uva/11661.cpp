#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
char s[2000010];
int d[1000000];
int r[1000000];
int main()
{
	int N;

	while(1)
	{
		scanf("%d",&N);
		if(N==0)break;;
		getchar();
		gets(s);
		int len=strlen(s);
		int i;
		bool k=false;
		int dd=0,rr=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='Z')
			{
				k=true;
				printf("0\n");
				break;
			}
			else if(s[i]=='D')
			{
				d[dd]=i;
				dd++;
			}
			else if(s[i]=='R')
			{
				r[rr]=i;
				rr++;
			}
		}

		if(k)continue;
		int ans=9999999;
		int l,p;
		for(l=0;l<rr;l++)
		{
			for(p=0;p<dd;p++)
			{
				ans=min(ans,abs(r[l]-d[p]));
			}
		}
		//printf("done");
		printf("%d\n",ans);
	}
    return 0;
}
