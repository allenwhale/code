#include <stdio.h>
#include <string.h>
long long change(long long n)
{
	char s[20],ss[20];
	sprintf(s,"%lld",n);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		ss[i]=s[len-1-i];
	}
	ss[len]='\0';
	long long ans;
	sscanf(ss,"%lld",&ans);
	return ans;
}
bool check(long long n)
{
	char s[20],ss[20];
	sprintf(s,"%lld",n);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[len-i-1])return false;
	}
	return true;
}
int main()
{
	
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		long long st;
		int  num=0;
		scanf("%lld",&st);
		while(1)
		{
			st=st+change(st);
			num++;
			if(check(st)==true)break;
		}
		printf("%d %lld\n",num,st);;
	}
    return 0;
}
