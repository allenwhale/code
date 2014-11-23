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
struct Node
{
	int idx;
	Node *l,*r;
	Node(int _i=-1)
	{
		l=r=0;
		idx=_i;
	}
	
}*root;
bool wrong;
struct Node2
{
	int idx,;
	char s[300];
	bool operator < (const Node2& nn)const
	{
		int l1=strlen(s),l2=strlen(nn.s);
		if(l1==l2)
		{
			if(strcmp(s,nn.s)==0)wrong=false;
			for(int i=0;i<l1;i++)
			{
				if(s[i]==nn.s[i])continue;
				if(s[i]=='L')return true;
				else return false;
			}
		}	
		else return l1<l2;
	}
}n[300];
int nn=0;
int main()
{
	char tmp[300];
	while(~scanf("%s",tmp))
	{
		wrong=true;
		nn=0;
		root=new Node();
		do
		{
			if(strcmp(tmp,"()")==0)break;
			sscanf(tmp,"(%d,%s",&n[nn].idx,n[nn].s);
			n[nn].s[strlen(n[nn].s)-1]=0;
			nn++;
		}while(scanf("%s",tmp));
		sort(n,n+nn);
		if(!wrong)
		{
			puts("not complete");
			continue;
		}
		bool tf=true;
		for(int i=0;i<nn&&tf;i++)
		{
			int len=strlen(n[i].s);
			Node *nd=root;
			for(int j=0;j<len&&tf;j++)
			{
				if(nd->idx==-1)tf=false;
				if(n[i].s[j]=='L')
				{
					if(nd->l==NULL)nd->l=new Node();
					nd=nd->l;
				}
				else
				{
					if(nd->r==NULL)nd->r=new Node();
					nd=nd->r;
				}
			}
			nd->idx=n[i].idx;
		}
		if(!tf)puts("not complete");
		else
		{
			for(int i=0;i<nn;i++)
			{
				printf("%d%c",n[i].idx,i==nn-1?'\n':' ');
			}
		}
	}
 	return 0;
}

