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
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		N=abs(N);
		int ans=-1;
		for(int i=0;;i++)
		{
			if((i*(i+1))/2>=N&&(((i*(i+1))/2-N)&1)==0)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",N==0?3:ans);
		if(T)puts("");
	}
	return 0;
}

