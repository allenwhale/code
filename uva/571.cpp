#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int mp[1010][1010];
/*
1: fill A
2: fill B
3: empty A
4: empty B
5: pour A B
6: pour B A
*/
int met[1010][1010];
bool vis[1010][1010];
int A,B,N;
void init()
{
	MS(met,-1);
	MS(mp,0x3f);
	MS(vis,false);
}
int main()
{
	while(~scanf("%d %d %d",&A,&B,&N))
	{
		if(B==N)
		{
			puts("fill B");
			puts("success");
			continue;
		}
		int a=0,b=0;
		while(b!=N)
		{
			if(a==0)
			{
				a=A;
				puts("fill A");
			}
			if(b!=B)
			{
				puts("pour A B");
				if(B-b<a)
				{
					a-=(B-b);
					b=B;
				}
				else
				{
					b+=a;
					a=0;
				}
			}
			if(b==B)
			{
				puts("empty B");
				b=0;
				puts("pour A B");
				b=a;
				a=0;
			}
		}
		puts("success");
	}
	return 0;
}

