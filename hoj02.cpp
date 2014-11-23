#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
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
pair<int,int>l[100010];
vector<pair<int,int> >vc;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vc.clear();
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			l[i]=make_pair(x,y);
		}
		sort(l,l+N);
		vc.push_back(make_pair(l[0].first,0));
		vc.push_back(make_pair(l[0].second,0));
		for(int i=1;i<N;i++)
		{
			if(l[i]==l[i-1])continue;
			vc.push_back(make_pair(l[i].first,i));
			vc.push_back(make_pair(l[i].second,i));
		}
		sort(vc.begin(),vc.end());
		stack<int>st;
		foreach(it,vc)
		{
			if(st.size()==0)st.push(it->second);
			else
			{
				if(st.top()==it->second)st.pop();
				else st.push(it->second);
			}
		}
		
		if(st.size()==0)
			puts("Y");
		else puts("N");
	}
	return 0;
}

