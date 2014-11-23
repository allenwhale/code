#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <time.h>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#ifndef _PUSH_POP_
#define _PUSH_POP_
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#endif
#ifndef _MS_
#define _MS_
#define MS(s,v) memset(s,v,sizeof(s))
#endif
#ifndef _PAIR_
#define _PAIR_
#define PI pair<int,int>
#define PD pair<double,double>
#define PL pair<long long,long long>
#define MP(a,b) make_pair(a,b)
#define FF first
#define SS second
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
int s[90];
int t[256];
int addh[]={0,1,2,3,4,5,6,7,8};
int addv[]={0,9,18,27,36,45,54,63,72};
int addb[]={0,1,2,9,10,11,18,19,20};
int st[10000],stb=0;
int get(int sp)
{
	do 
	{
		sp++;
	}while(sp<81&&s[sp]!=0);
	return sp;
}
bool check(int sp,int st,int* add)
{
	int c=s[sp];
	for(int i=0;i<9;i++)
	{
		int p=st+add[i];
		//if(p==sp)continue;
		if(p!=sp&&s[p]==c)return false;
	}
	return true;
}
void print()
{
	for(int i=0;i<81;i++)
	{
		printf("%d ",s[i]);
		if(i%9==8)puts("");
	}
}
void solve()
{
	int sp=get(-1);
	do
	{
		//printf(" %d\n",sp);
		//if(sp>54)	print(),system("pause");
		s[sp]++;
		if(s[sp]>9)
		{
			s[sp]=0;
			sp=st[--stb];
			continue;
		}
		else
		{
			if(!check(sp,sp/9*9,addh)
				||!check(sp,sp%9,addv)
				||!check(sp,((sp/9)/3)*27+((sp%9)/3)*3,addb))continue;
			
			st[stb++]=sp;
			sp=get(sp);
		}
	}while(sp>=0&&sp<81);
}

int main()
{
	//b¡Bc¡Bd¡Bp¡Br¡Bt¡Bv¡Bw  y
	t['b']=1;
	t['c']=2;
	t['d']=3;
	t['p']=4;
	t['r']=5;
	t['t']=6;
	t['v']=7;
	t['w']=8;
	t['y']=9;
	MS(s,0);
	//set
	int a,n;
	scanf("%d %d",&a,&n);
	
	for(int i=0;i<a;i++)
	{
		char c;
		int ptr;
		scanf("%d %c",&ptr,&c);
		s[9*(ptr/10-1)+(ptr%10)-1]=t[(int)c];
	}/*
	for(int i=0;i<a;i++)
	{
		int aa,b,c;
		scanf("%d %d %d",&aa,&b,&c);
		s[aa*9+b]=c;
	}*/
	solve();
	for(int i=0;i<81;i++)
	{
		printf("%d ",s[i]);
		if(i%9==8)puts("");
	}
 	return 0;
}

