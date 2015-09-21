#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int d[1010];
int N;
void init()
{
	for(int i=0;i<=1000;i++)
	{
		d[i]=i;
	}
}
int find(int x)
{
	return x==d[x]?x:d[x]=find(d[x]);
}
void U(int a,int b)
{
	d[find(a)]=find(b);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%*c",&N);
		char s[100];
		int y=0,n=0;
		while(gets(s)!=NULL&&strcmp(s,"")!=0)
		{
			char c;
			int f,t;
			sscanf(s,"%c %d %d",&c,&f,&t);
			if(c=='c')
			{
				U(f,t);
			}
			else if(c=='q')
			{
				if(find(t)==find(f))y++;
				else n++;
			}
		}
		printf("%d,%d\n",y,n);
		if(T)puts("");
	}
	return 0;
}

