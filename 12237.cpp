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
int MOD[100010];
int main()
{
	int N,C;
	while(~scanf("%d %d",&C,&N)&&N)
	{
		//puts("in");
		MS(MOD,-1);
		MOD[0]=0;
		int sum=0;
		bool tf=false;
		for(int i=1;i<=N;i++)
		{
			int idx;
			scanf("%d",&idx);
			int mod=(sum+idx)%C;
			sum=mod;
			if(MOD[mod]==-1)MOD[mod]=i;
			else if(!tf)
			{
				for(int j=MOD[mod]+1;j<=i;j++)
					printf("%d%c",j,j==i?'\n':' ');
				tf=true;
				//break;
			}
		}
		if(!tf)
		{
			puts("No sweets");
		}
	}
	return 0;
}

