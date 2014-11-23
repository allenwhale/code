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
int dp[35][30];
vector<int>vc[30];
vector<int>sp;
int main()
{
	int N,M;
	while(~scanf("%d%*c",&N))
	{
		for(int i=0;i<26;i++)vc[i].clear();
		sp.clear();
		for(int i=0;i<N;i++)
		{
			char a,b,c,d;
			scanf("%c %c %c %c%*c",&a,&b,&c,&d);
			int aa=a-'A',bb=b-'A',cc=c-'A';
			vc[aa].push_back(bb);
			vc[aa].push_back(cc);
			if(d=='x')sp.push_back(aa);
		}
		scanf("%d",&M);
		MS(dp,0);
		dp[0][0]=1;
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<26;j++)
			{
				foreach(it,vc[j])
				{
					dp[i+1][*it]+=dp[i][j];
				}
			}
		}
		int ans=0;
		foreach(it,sp)
			ans+=dp[M][*it];
		printf("%d\n",ans);
	}
	return 0;
}

