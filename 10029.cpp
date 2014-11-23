#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,int>mp[10007];
hash<string> _hash;
#define HASH(s) (_hash(s)%10007)
int main()
{
	char s[30];
	string in;
	int ans=1;
	while(gets(s)!=NULL)
	{
		in=string(s);
		int len=strlen(s);
		int mx=1;
		//change	
		for(int i=0;i<len;i++)
		{
			for(char j='a';j<='z';j++)
			{
				string tmp=in.substr(0,i)+j+in.substr(i+1);
				auto it=mp[HASH(tmp)].find(tmp);
				if(it!=mp[HASH(tmp)].end())mx=max(mx,it->second+1);
				if(tmp>in)break;
			}
		}
		//delete
		for(int i=0;i<len;i++)
		{
			string tmp=in.substr(0,i)+in.substr(i+1);
			auto it=mp[HASH(tmp)].find(tmp);
			if(it!=mp[HASH(tmp)].end())mx=max(mx,it->second+1);
		}
		//add
		for(int i=0;i<=len;i++)
		{
			for(char j='a';j<='z';j++)
			{
				string tmp=in.substr(0,i)+j+in.substr(i);
				auto it=mp[HASH(tmp)].find(tmp);
				if(it!=mp[HASH(tmp)].end())mx=max(mx,it->second+1);
				if(tmp>in)break;
			}
		}
		mp[HASH(in)][in]=max(mp[HASH(in)][in],mx);
		ans=max(ans,mx);
	}
	printf("%d\n",ans);
	return 0;
}