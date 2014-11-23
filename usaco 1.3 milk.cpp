/*
ID: allenwh1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
deque< pair<int,int> >milk;
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int all,sup;
	scanf("%d %d",&all,&sup);
	for(int i=0;i<sup;i++)
	{
		int per,m;
		scanf("%d %d",&per,&m);
		milk.push_back(make_pair(per,m));
	}
	sort(milk.begin(),milk.end());
	int now=0;
	for(int i=0;all>0;i++)
	{
		int per=milk[i].first,m=milk[i].second;
		if(all>=m)
		{
			now+=m*per;
			all-=m;
		}
		else
		{
			now+=all*per;
			all=0;
		}
	}
	printf("%d\n",now);
    return 0;
}
