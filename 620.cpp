#include <stdio.h>
#include <string.h>
#define MAXN 1010
char s[MAXN];
int find(int a,int b)
{
	if(a==b)
	{
		if(s[a]=='A')return 1;
		else return 0;
	}
	if(s[b-1]=='A'&&s[b]=='B')
	{
		if(find(a,b-2))
			return 2;
		return 0;
	}
	if(s[a]=='B'&&s[b]=='A')
	{
		if(find(a+1,b-1))
			return 3;
		return 0;
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int c=find(0,strlen(s)-1);
		if(c==1)puts("SIMPLE");
		else if(c==2)puts("FULLY-GROWN");
		else if(c==3)puts("MUTAGENIC");
		else puts("MUTANT");
	}
	return 0;
}
