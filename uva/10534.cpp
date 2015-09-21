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
#define MAXN 10010
vector<int>vc;
int s[MAXN],dlis[MAXN],dlds[MAXN];
int N;
int main()
{
	while(~scanf("%d",&N))
	{
		for(int i=0;i<N;i++)
			scanf("%d",&s[i]);
		//LIS
		vc.clear();
		vc.push_back(s[0]);
		dlis[0]=1;
		for(int i=1;i<N;i++)
		{
			if(s[i]>vc.back())vc.push_back(s[i]),dlis[i]=SIZE(vc);
			else
			{	
				vector<int>::iterator it=lower_bound(vc.begin(),vc.end(),s[i]);
				dlis[i]=(int)(it-vc.begin()+1);
				vc[dlis[i]-1]=s[i];
			}
		}
		reverse(s,s+N);
		//LDS
		vc.clear();
		vc.push_back(s[0]);
		dlds[0]=1;
		for(int i=1;i<N;i++)
		{
			if(s[i]>vc.back())vc.push_back(s[i]),dlds[i]=SIZE(vc);
			else
			{	
				vector<int>::iterator it=lower_bound(vc.begin(),vc.end(),s[i]);
				dlds[i]=(int)(it-vc.begin()+1);
				vc[dlds[i]-1]=s[i];
			}
		}
		int ans=0;
		for(int i=0;i<N-1;i++)
		{
			ans=max(ans,-1+2*min(dlis[i],dlds[N-i-1]));
		}
		printf("%d\n",ans);
	}
	return 0;
}

