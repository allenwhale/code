#include <stdio.h>
#include <string.h>
bool prime(int s)
{
	int i;
	if(s==0||s==1)return false;
	if(s==2)return true;
	for(i=2;i*i<s+1;i++)
	{
		if(s%i==0)return false;
	}
	return true;
}
int main()
{
	int N;
	scanf("%d",&N);
	int i,j;
	getchar();
	for(i=1;i<=N;i++)
	{
		
		int f[300];
		char s[2010];
		memset(f,0,sizeof(f));
		gets(s);
		int len=strlen(s);
		for(j=0;j<len;j++)
		{
			f[s[j]]++;
		}
		bool ans=false;
		printf("Case %d: ",i);
		for(j=0;j<300;j++)
		{
			if(prime(f[j])==true)
			{
				ans=true;
				printf("%c",j);				
			}
		}
		if(!ans)printf("empty");
		printf("\n");
	}
    return 0;
}
