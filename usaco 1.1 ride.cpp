/*
ID: allenwh1
PROG: ride
LANG: C++
*/
#include <stdio.h>
int a(char c)
{
	return c-'A'+1;
}
int main()
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	char s[10];
	gets(s);
	int ufo=1;
	int i=0;
	while(s[i]!='\0')
	{
		ufo*=a(s[i]);
		i++;
	}
	gets(s);
	int now=1;
	i=0;
	while(s[i]!='\0')
	{
		now*=a(s[i]);
		i++;
	}
	if(now%47==ufo%47)printf("GO\n");
	else printf("STAY\n");
    return 0;
}
