#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctype.h>
#include <set>
#include <map>
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
int t[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
map<int,int>mp;
set<int>vc;
int main()
{
	int T_;
	scanf("%d",&T_);
	while(T_--)
	{
		int N;scanf("%d",&N);
		char s[100];
		mp.clear();vc.clear();
		for(int i=0;i<N;i++)
		{
			scanf("%s",s);
			int p=0;
			for(int j=0;s[j];j++)
			{
				if(s[j]=='-')continue;
				if(isdigit(s[j]))
				{
					p*=10;p+=(s[j]-'0');
				}
				else
				{
					p*=10;p+=(t[s[j]-'A']);
				}	
			}
			if(mp.count(p)==0)mp[p]=1;
			else
			{
				vc.insert(p);
				mp[p]++;
			}
				//printf("   %d\n",p);
		}
		if(SIZE(vc)==0)puts("No duplicates.");
		else
		{
			foreach(it,vc)
			{
				printf("%03d-%04d %d\n",*it/10000,*it%10000,mp[*it]);
			}
		}
		if(T_)puts("");
	}
	return 0;
}

