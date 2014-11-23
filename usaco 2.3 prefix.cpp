/*
ID: allenwh1
PROG: prefix
LANG: C++
*/
#include <map>
#include <iostream>
#include <stdio.h>
#include <string.h>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
map<int,int>mp;
char p[20],s[2000020];
int main()
{
	fin("prefix.in");
	fout("prefix.out");
	bool tf[1000020];
	memset(tf,false,sizeof(tf));
	while(scanf("%s",p))
	{
		if(p[0]=='.')break;
		int len=strlen(p);
		int q=0;
		for(int i=len-1;i>=0;i--)
		{
			q=q*171+p[i];
		}
		mp[q]=1;
	}
	char c;
	int total=0;
	tf[0]=true;
	while(~scanf("%c",&c))
	{
		if(c<'A'||c>'Z')continue;
		s[++total]=c;
		int q=0;
		for(int i=1;i<=10;i++)
		{
			if(total-i<0)break;
			q=q*171+s[total-i+1];
			if(mp.find(q)!=mp.end()&&tf[total-i])
			{
				tf[total]=true;
				break;
			}
		}
	}
	for(int i=total;i>=0;i--)
	{
		if(tf[i]||i==0)
		{
			printf("%d\n",i);
			break;
		}
	}
    return 0;
}
