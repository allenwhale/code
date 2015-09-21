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
struct sta
{
	int n;
	int a,b;
	sta(){}
	sta(int _n,int _a)
	{
		n=_n,a=_a;
	}
	sta(int _n,int _a,int _b)
	{
		n=_n,a=min(_a,_b),b=max(_a,_b);
	}
};
vector<sta>vc;
int N;
int s[10100];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vc.clear();
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
		}
		sort(s,s+N);
		int last=N;
		int ans=0;
		while(last>3)
		{
			int t1=s[last-1]+s[last-2]+2*s[0];
			int t2=s[1]+s[0]+s[last-1]+s[1];
			if(t1<t2)
			{
				ans+=t1;
				vc.push_back(sta(2,s[0],s[last-1]));
				vc.push_back(sta(1,s[0]));
				vc.push_back(sta(2,s[0],s[last-2]));
				vc.push_back(sta(1,s[0]));
			}
			else
			{
				ans+=t2;
				vc.push_back(sta(2,s[0],s[1]));
				vc.push_back(sta(1,s[0]));
				vc.push_back(sta(2,s[last-1],s[last-2]));
				vc.push_back(sta(1,s[1]));
			}
			last-=2;
		}
		if(last==3)
		{
			ans+=(s[0]+s[1]+s[2]);
			vc.push_back(sta(2,s[0],s[1]));
			vc.push_back(sta(1,s[0]));
			vc.push_back(sta(2,s[0],s[2]));
		}
		else if(last==2)
		{
			ans+=s[1];
			vc.push_back(sta(2,s[0],s[1]));
		}
		else if(last==1)
		{
			ans+=s[0];
			vc.push_back(sta(1,s[0]));
		}
		printf("%d\n",ans);
		foreach(it,vc)
		{
			if((*it).n==1)printf("%d\n",(*it).a);
			else printf("%d %d\n",(*it).a,(*it).b);
		}
		if(T)puts("");
	}
	return 0;
}

