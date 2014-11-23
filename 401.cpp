#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;
map<char,char>mp;
void init()
{
	mp.insert(make_pair('A','A'));
	mp.insert(make_pair('E','3'));
	mp.insert(make_pair('3','E'));
	mp.insert(make_pair('H','H'));
	mp.insert(make_pair('I','I'));
	mp.insert(make_pair('J','L'));
	mp.insert(make_pair('L','J'));
	mp.insert(make_pair('O','O'));
	mp.insert(make_pair('S','2'));
	mp.insert(make_pair('T','T'));
	mp.insert(make_pair('U','U'));
	mp.insert(make_pair('V','V'));
	mp.insert(make_pair('W','W'));
	mp.insert(make_pair('M','M'));
	mp.insert(make_pair('Y','Y'));
	mp.insert(make_pair('X','X'));
	mp.insert(make_pair('Z','5'));
	mp.insert(make_pair('2','S'));
	mp.insert(make_pair('5','Z'));
	mp.insert(make_pair('8','8'));
}
char s[100];
bool mirror()
{
	int len=strlen(s);
	//printf("m %d\n",len);
	for(int i=0,j=len-1;i<=j;i++,j--)
	{
		if(mp[s[i]]!=s[j]||s[i]=='0'||s[j]=='0')return false;
	}
	return true;
}
bool palindrome()
{
	int len=strlen(s);
	//printf("p %d\n",len);
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])return false;
	}
	return true;
}
int main()
{
	init();
	
	while(~scanf("%s",s))
	{
		//printf("len %d %s\n",strlen(s),s);
		bool m=mirror(),p=palindrome();
		//printf("%d %d \n",m,p);
		for(int i=0;s[i];i++)
		{
			if(s[i]=='0')s[i]='O';
		}
		if(m&&p)
		{
			printf("%s -- is a mirrored palindrome.\n",s);
		}
		else if(!m&&p)
		{
			printf("%s -- is a regular palindrome.\n",s);
		}
		else if(!p&&m)
		{
			printf("%s -- is a mirrored string.\n",s);
		}
		else if(!m&&!p)
		{
			printf("%s -- is not a palindrome.\n",s);
		}
		puts("");
	}
	return 0;
}
