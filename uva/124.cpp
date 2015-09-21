#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
deque<int>DQ[26];
int num[26];
bool ex[26];
int con;
int ans[26];
void inti()
{
	memset(num,0,sizeof(num));
	memset(ex,false,sizeof(ex));
	memset(ans,0,sizeof(ans));
	con=0;
	int i;
	for(i=0;i<26;i++)
	{
		DQ[i].clear();
	}
}
void print()
{
	int i;
	for(i=0;i<con;i++)
	{
		printf("%c",ans[i]+'a');
	}
	printf("\n");
}
void sort(int n)
{
	int i,j;
	for(i=0;i<26;i++)
	{
		if(ex[i]&&num[i]==0)
		{
			ans[n]=i;
			n++;			
			if(n==con)
			{
				n--;
				print();
				return;
			}
			ex[i]=false;
			int size=DQ[i].size();
			for(j=0;j<size;j++)
			{
				num[DQ[i][j]]--;
			}
			sort(n);
			for(j=0;j<size;j++)
			{
				num[DQ[i][j]]++;
			}
			ex[i]=true;
			n--;
		}
	}
	return;
}
int main()
{
	char s[310];
	bool p=true;
	while(gets(s)!=NULL)
	{		
		int i=0;
		inti();
		int size=strlen(s);
		for(i=0;i<size;i=i+2)
		{
			ex[s[i]-'a']=true;
			con++;
		}
		gets(s);
		i=0;
		size=strlen(s);
		for(i=0;i<size;i=i+4)
		{
			DQ[s[i]-'a'].push_back(s[i+2]-'a');
			num[s[i+2]-'a']++;
		}
		if(!p)printf("\n");
		p=false;
		sort(0);		
	}
    return 0;
}
