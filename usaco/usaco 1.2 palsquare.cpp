/*
ID: allenwh1
PROG: palsquare
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char ans[100];
char pre[100];
char turn(int a)
{
	if(a<10)return a+'0';
	return (a-10)+'A';
}
int to(int s,int b)
{
	int i=0;
	while(s!=0)
	{
		ans[i++]=turn(s%b);
		s=s/b;
	}
	return i;
}
int topre(int s,int b)
{
	int i=0;
	while(s!=0)
	{
		pre[i++]=turn(s%b);
		s=s/b;
	}
	return i;
}
bool tf(int l)
{
	int s,e;
	for(s=0,e=l-1;s<=e;s++,e--)
	{
		if(ans[s]!=ans[e])return false;
	}
	return true;
}
void t(int l)
{
	int s,e;
	for(s=0,e=l-1;s<=e;s++,e--)
	{
		swap(pre[s],pre[e]);
	}
}
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=300;i++)
	{
		int tmp=i*i;
		fill(ans,ans+100,'\0');
		fill(pre,pre+100,'\0');
		int len=to(tmp,N);		
		if(tf(len))
		{
			int l=topre(i,N);
			t(l);
			printf("%s %s\n",pre,ans);
		}
	}
    return 0;
}
