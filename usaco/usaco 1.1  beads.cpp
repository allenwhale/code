/*
ID: allenwh1
PROG: beads
LANG: C++
*/
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
char s[1000];	
bool vis[1000];
int N;
int a(int f)
{
	char c=s[f];
	int ans=0;
	if(c=='w')
	{
		while(!vis[f]&&s[f]==c)
		{
			vis[f]=true;
			ans++;
			f--;
			f=(f+N)%N;
		}
		c=s[f];
	}
	while(!vis[f]&&(s[f]==c||s[f]=='w'))
	{
		vis[f]=true;
		ans++;
		f--;
		f=(f+N)%N;
	}
	return ans;
}
int b(int t)
{
	char c=s[t];
	int ans=0;
	if(c=='w')
	{
		while(s[t]==c&&!vis[t])
		{
			vis[t]=true;
			ans++;
			t++;
			t=t%N;
		}
		c=s[t];
	}
	while(!vis[t]&&(s[t]==c||s[t]=='w'))
	{
		vis[t]=true;
		ans++;
		t++;
		t=t%N;
	}
	return ans;
}
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d",&N);
	getchar();
	gets(s);
	int f,t;
	int mx=0;
	for(f=0,t=1;t<N;f++,t++)
	{
		memset(vis,false,sizeof(vis));
		int tmp=a(f)+b(t);
		mx=max(mx,tmp);
	}
	printf("%d\n",mx);
    return 0;
}
