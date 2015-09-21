/*
ID: allenwh1
PROG: gift1
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
map<string,int>mp;
map<string,int>::iterator it;
int sn=0;
char n[20][20];
int find(char a[])
{
	if(mp.count(a)==0)
	{
		strcpy(n[sn],a);
		mp[a]=sn++;
	}
	return mp[a];
}
int s[20][2];
int ans[20];
int N;
int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	scanf("%d",&N);
	char name[20],name2[20];
	for(int i=0;i<N;i++)
	{
		//printf("%d",i);
		scanf("%s",name);
		//printf("%s",name);
		find(name);
	}
	int now,to;
	for(int i=0;i<N;i++)
	{
		scanf("%s",name);
		scanf("%d %d",&now,&to);
		ans[find(name)]-=now;
		if(to==0)continue;
		int avg=now/to;
		ans[find(name)]+=now%to;
		//ans[find(name)]-=avg*to;
		for(int j=0;j<to;j++)
		{
			scanf("%s",name2);
			ans[find(name2)]+=avg;
		}
	}
	for(int i=0;i<sn;i++)
	{
		printf("%s %d\n",n[i],ans[i]);
	}
    return 0;
}
