/*
ID: allenwh1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <string.h>
#include <deque>
#include <stdio.h>
#include <ctype.h>
using namespace std;
deque< pair<char,int> >dq;	
int ln=0;
char s[40000];
pair<int,int> abc(int mid)
{
	pair<int,int>pr;
	int len=1;
	pr=make_pair(len,mid);
	for(int i=mid-1,j=mid+1;i>=0&&j<ln;i--,j++)
	{
		if(dq[i].first!=dq[j].first)return pr;
		pr.first+=2;
		pr.second=i;
	}
	//pr=make_pair(len,i);
	return pr;
}
pair<int,int> cba(int mid)
{
	pair<int,int>pr;
	int len=0;
	pr=make_pair(len,mid);
	for(int i=mid,j=mid+1;i>=0&&j<ln;i--,j++)
	{
		if(dq[i].first!=dq[j].first)return pr;
		pr.first+=2;
		pr.second=i;
	}
	return pr;
}
int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	char c;
	int an=0;

	int st=1e9,en;
	int len=0;
	while(~scanf("%c",&c))
	{		
		s[an++]=c;
		c=toupper(c);
		if(c>='A'&&c<='Z')dq.push_back(make_pair(c,an-1)),ln++;
	}
	pair<int,int>pr;
	for(int i=0;i<ln;i++)
	{
		pr=abc(i);
		if(len<pr.first)
		{
			len=pr.first;
			st=pr.second;
			en=st+len-1;
		}
		else if(len==pr.first)
		{
			if(st>pr.second)
			{
				st=pr.second;
				en=st+len-1;
			}
		}
	}
	for(int i=0;i<ln-1;i++)
	{
		pr=cba(i);
		if(len<pr.first)
		{
			len=pr.first;
			st=pr.second;
			en=st+len-1;
		}
		else if(len==pr.first)
		{
			if(st>pr.second)
			{
				st=pr.second;
				en=st+len-1;
			}
		}
	}
	printf("%d\n",len);
	st=dq[st].second;
	en=dq[en].second;
	for(int i=st;i<=en;i++)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	//while(1);
    return 0;
}
