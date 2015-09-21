#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
map<string,int>mp;
char s[100000];
char longs[100000];
int longlen=0;
int main()
{
	while(gets(s)!=NULL)
	{
		if(mp.count(s)==0)
		{
			mp[s]=1;
		}
		else mp[s]++;
		if(longlen<mp[s])
		{
			longlen=mp[s];
			strcpy(longs,s);
		}
		else if(longlen==mp[s]&&strlen(longs)<strlen(s))
		{
			strcpy(longs,s);
		}
	}
	puts(longs);
	printf("%d\n",longlen);
	return 0;
}

