/*
ID: allenwh1
PROG: milk2
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
pair<int,int>tmpmilk;
deque< pair<int,int> >milk;
int N;
int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int b,e;
		scanf("%d %d",&b,&e);
		tmpmilk=make_pair(b,e);
		milk.push_back(tmpmilk);
	}
	sort(milk.begin(),milk.end());
	int m=0;
	for(int i=1;i<N;i++)
	{
		int pree=milk[m].second,preb=milk[m].first,nowb=milk[i].first,nowe=milk[i].second;
		if(pree>=nowb)milk[m]=make_pair(preb,max(nowe,pree));
		else milk[++m]=make_pair(nowb,nowe);
	}
	int get=0,non=0,pree=milk[0].first;
	for(int i=0;i<=m;i++)
	{
		
		int b=milk[i].first,e=milk[i].second;
		get=max(get,e-b);
		non=max(non,b-pree);
		pree=e;
	}
	printf("%d %d\n",get,non);
    return 0;
}
