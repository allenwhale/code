#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
using namespace std;
int n[26];
bool ex[26];
deque<int>DQ[26];
int main()
{
	memset(n,0,sizeof(n));
	memset(ex,false,sizeof(ex));
	char s1[30],s2[30];
	gets(s1);
	int i;
	int size=strlen(s1);
	for(i=0;i<size;i++)
	{
		ex[s1[i]-'A']=true;
	}
	while(gets(s2))
	{
		if(s2[0]=='#')break;
		size=strlen(s2);
		for(i=0;i<size;i++)
		{
			ex[s2[i]-'A']=true;
		}
		i=0;
		while(1)
		{
			if(s1[i]=='\0'||s2[i]=='\0')
			{
				i=99999;
				break;
			}
			if(s1[i]!=s2[i])break;
			i++;
		}
		if(i==99999)
		{
			strcpy(s1,s2);
			continue;
		}
		DQ[s1[i]-'A'].push_back(s2[i]-'A');
		n[s2[i]-'A']++;
		strcpy(s1,s2);
	}
	int con=0; 
	for(i=0;i<26;i++)
	{
		if(ex[i])con++;
	}
	int ans[26];
	for(i=0;i<con;i++)
	{
		int j=0,now;
		for(j=0;j<26;j++)
		{
			if(ex[j]&&n[j]==0)
			{
				now=j;
				break;
			}
		}
		ans[i]=now;
		ex[now]=false;
		size=DQ[now].size();
		for(j=0;j<size;j++)
		{
			n[DQ[now][j]]--;
		}
	}
	for(i=0;i<con;i++)
	{
		printf("%c",ans[i]+'A');
	}
	printf("\n");
	//while(1);
    return 0;
}
