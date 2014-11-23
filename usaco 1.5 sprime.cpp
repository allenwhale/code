/*
ID: allenwh1
PROG: sprime
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define fo freopen
int p[100000];
int sn=0;
int l;
bool isp(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)return false;
	}
	return x==1?false:true;
}
bool tf(int x) 
{
	while(x>0)
	{
		//printf(" %d\n",x);
		if(!isp(x))return false;
		x/=10;
	}
	return true;
}
void DFS(int n,int now)
{
	if(!isp(now))return;
	if(n==l-1)
	{
		p[sn++]=now;
		return;
	}
	for(int i=1;i<10;i+=2)
	{
		DFS(n+1,now*10+i);
	}
}
int main()
{
	fo("sprime.in","r",stdin);
	fo("sprime.out","w",stdout);
	scanf("%d",&l);
	int end;
	int s=1;
	for(int i=1;i<l;i++)
	{
		s*=10;
	}
	DFS(0,2);
	DFS(0,3);
	DFS(0,5);
	DFS(0,7);
	sort(p,p+sn);	
	for(int i=0;i<sn;i++)
	{
		if(p[i]>s)printf("%d\n",p[i]);
	}
    return 0;
}
