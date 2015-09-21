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
	int N;
	while(~scanf("%d",&N))
	{
		int c=N/5;
		int ans=-1;
		for(int i=c;i>=0;i--)
		{
			if((N-i*5)%3==0)
			{
				ans=i+(N-i*5)/3;
				break;
			}
		}
		if(ans!=-1)printf("%d\n",ans);
		else printf("This is Kongming's Trap!!!\n");
	}
	return 0;
}

