#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int s[10];
bool c[6*10000+10];
int all,half;
int read()
{
	int sum=0;
	for(int i=1;i<=6;i++)scanf("%d",&s[i]),sum+=s[i]*i;
	return sum;
}
bool find(int m)
{
	MS(c,false);
	c[0]=true;
	for(int i=1;i<=6;i++)
	{
		//printf("%d\n",i);
		int left=s[i];
		if(left==0)continue;
		for(int j=0;j<i;j++)
		{
			for(int k=j;k<=m;k+=i)
			{
				if(c[k])left=s[i];
				else if(k-i>=0&&c[k-i]&&left>0)
				{
					left--;
					c[k]=true;
					//printf(" %d\n",k);
				}
			}
		}
	}
	return c[m];
}
int main()
{
	int t=1;
	while((all=read()))
	{
		printf("Collection #%d:\n",t++);
		if(all&1)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		half=all/2;
		if(find(half))printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
	return 0;
}

