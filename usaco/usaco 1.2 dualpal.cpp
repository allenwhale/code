/*
ID: allenwh1
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char ans[100];
char turn(int a)
{
	if(a<10)return a+'0';
	return a-10+'A';
}
int to(int s,int b)
{
	int i=0;
	while(s!=0)
	{
		ans[i++]=turn(s%b);
		s/=b;
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
int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s,now=0;
	scanf("%d %d",&n,&s);
	for(int i=s+1;now<n;i++)
	{
		int nt=0;
		for(int j=2;j<=10&&nt<2;j++)
		{
			int len=to(i,j);
			if(tf(len))nt++;
		}
		if(nt==2)printf("%d\n",i),now++;
	}
    return 0;
}
