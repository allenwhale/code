/*
ID: allenwh1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int num[300];
int no[300];
int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int m,s,n;
	scanf("%d %d %d",&m,&s,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	int f=num[0]-1,t=s-num[n-1];
	int cost=f+t;
	for(int i=0;i<n-1;i++)
	{
		no[i]=num[i+1]-num[i]-1;
	}
	sort(no,no+n-1);
	for(int i=n-2,now=0;now<m-1&&i>=0;i--,now++)
	{
		//printf("\t%d\n",no[i]);
		cost+=no[i];
	}
	printf("%d\n",s-cost);
    return 0;
}
