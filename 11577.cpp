#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	char s[210];
	int num[300];
//printf("%d %d",'a','z');
	scanf("%d",&N);
	getchar();
	int i;
	for(i=1;i<=N;i++)
	{
		gets(s);
		memset(num,0,sizeof(num));
		int len=strlen(s);
		int j;
		for(j=0;j<len;j++)
		{
			if(s[j]<97)s[j]=s[j]+32;
			if(s[j]>'z'||s[j]<'a')continue;
			num[s[j]]++;
			//printf("\t%d\n",num[s[j]]);
		}
		int ans=0,ansn=0,ansc[100];
		for(j=97;j<=122;j++)
		{
			//printf("%c",j);
			if(ansn<num[j])
			{
				memset(ansc,0,sizeof(ansc));
				ans=0;
				ansn=num[j];
				ansc[ans]=j;
				//printf("\t%d %c\n",ansn,ansc[ans]);
			}
			else if(ansn==num[j])
			{
				ans++;
				ansc[ans]=j;
			}
		}
		//printf("%d",ans);
		sort(ansc,ansc+ans+1);
		for(j=0;j<=ans;j++)
		{
			printf("%c",ansc[j]);
		}
		printf("\n");
	}
    return 0;
}
