#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
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
int N;
long long s[1000010];
vector<long long>vc;
int main()
{
	while(~scanf("%d",&N))
	{
		vc.clear();
		long long sum=0;
		long long avg;
		for(int i=0;i<N;i++)
		{
			scanf(__lld,&s[i]);
			sum+=s[i];
		}
		avg=sum/N;
		vc.push_back(0ll);
		sum=0;
		for(int i=0;i<N-1;i++)
		{
			sum+=s[i];
			vc.push_back(sum-(i+1)*avg);
		}
		sort(vc.begin(),vc.end());
		long long mid;
		if(SIZE(vc)&1)
		{
			mid=vc[SIZE(vc)/2];
		}
		else
		{
			mid=(vc[SIZE(vc)/2]+vc[SIZE(vc)/2-1])/2;
		}
		long long ans=0;
		foreach(it,vc)
		{
			//printf("%d ",*(it));
			ans+=abs(mid-*(it));
		}
		//puts("");
		printf(__lld"\n",ans);
	}
	return 0;
}

