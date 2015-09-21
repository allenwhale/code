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
int z[10000];
void Z_func(char *s)
{
	int len=strlen(s);
	z[0]=len;
	int L=0,R=1;
	for(int i=1;i<len;i++)
	{
		if(R<=i||z[i-L]>=R-i)
		{
			int x=R<=i?i:R;
			while(x<len&&s[x]==s[x-i])x++;
			z[i]=x-i;
			if(i<x)L=i,R=x;
		}
		else z[i]=z[i-L];
	}
}
int main()
{
	char s[10000];
	int T=0;
	scanf("%d%*c",&T);
	while(T--)
	{
		//scanf("%s",s);
		getchar();
		gets(s);
		Z_func(s);
		int ans=-1;
		int len=strlen(s);
		//if(s[len-1]=='\n')len--;
		//printf("  %d\n",len);
		for(int i=1;i<len;i++)
		{
			if(z[i]+i==len&&len%(i)==0)
			{
				ans=i;break;
			}
		}
		if(ans!=-1)printf("%d\n",ans);
		else printf("%d\n",len);
		if(T)puts("");
	}
	return 0;
}

