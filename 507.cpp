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
	int _T;
	scanf("%d",&_T);
	int test=0;
	while(_T--)
	{
		int N,sum=0,st=-1,ans=-1,ed=-1,tmp=1;
		scanf("%d",&N);
		for(int i=2;i<=N;i++)
		{
			int idx;scanf("%d",&idx);
			sum+=idx;
			if(sum<0)sum=0,tmp=i;
			if(ans<sum)
			{
				ans=sum;
				st=tmp;
				ed=i;
			}
			else if(ans==sum&&tmp<=st)
			{
				st=tmp;ed=i;
			}
		}
		if(ans>0)
            printf("The nicest part of route %d is between stops %d and %d\n", ++test, st, ed);
        else
            printf("Route %d has no nice parts\n", ++test);
	}
	return 0;
}

