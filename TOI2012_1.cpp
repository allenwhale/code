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
map<char,int>var;
char s[110][10000];
int N;
int main()
{
	scanf("%d%*c",&N);
	for(int i=1;i<=N;i++)
		gets(s[i]);
	int don=1;
	while(true)
	{
		//printf(" %d\n",don);
		if(strcmp(s[don],"END")==0)break;
		char cmd[1000];
		sscanf(s[don],"%s",cmd);
		int i=don;
		if(strcmp(cmd,"IF")==0)
		{
			char v1[10],v2[10],op[10];
			int t,f;
			bool tf;
			sscanf(s[i],"%*s%s%s%s THEN GOTO %d ELSE GOTO %d",v1,op,v2,&t,&f);
			int n1,n2;
			if(v1[0]>'9'||v1[0]<'0')n1=var[v1[0]];
			else sscanf(v1,"%d",&n1);
			if(v2[0]>'9'||v2[0]<'0')n2=var[v2[0]];
			else sscanf(v2,"%d",&n2);
			if(strcmp(op,"<")==0)tf=n1<n2;
			else if(strcmp(op,">")==0)tf=n1>n2;
			else if(strcmp(op,"<=")==0)tf=n1<=n2;
			else if(strcmp(op,">=")==0)tf=n1>=n2;
			else if(strcmp(op,"=")==0)tf=n1==n2;
			else if(strcmp(op,"<>")==0)tf=n1!=n2;
			if(tf)don=t;
			else don=f;
		}
		else if(strcmp(cmd,"PRINT")==0)
		{
			char v[10];
			sscanf(s[i],"%*s %s",v);
			printf("%d\n",var[v[0]]);
			don++;
		}
		else
		{
			char v1[10],v2[10],op[10];
			sscanf(s[i],"%*s%*s%s %s %s",v1,op,v2);
			if(strlen(op)==0)
			{
				int n;
				if(v1[0]>'9'||v1[0]<'0')n=var[v1[0]];
				else sscanf(v1,"%d",&n);
				var[cmd[0]]=n;
			}
			int n1,n2;
			if(v1[0]>'9'||v1[0]<'0')n1=var[v1[0]];
			else sscanf(v1,"%d",&n1);
			if(v2[0]>'9'||v2[0]<'0')n2=var[v2[0]];
			else sscanf(v2,"%d",&n2);
			if(op[0]=='+')var[cmd[0]]=n1+n2;
			else if(op[0]=='-')var[cmd[0]]=n1-n2;
			else if(op[0]=='*')var[cmd[0]]=n1*n2;
			don++;
		}
	}
 	return 0;
}

