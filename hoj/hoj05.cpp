#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int N;
int mp[110][110];
int dis[110][110];
int main()
{
	while(~scanf("%d",&N))
	{
		MS(dis,0);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&mp[i][j]);
				if(mp[i][j]==0)mp[i][j]=1e8;
				dis[i][j]=mp[i][j];
			}
		}
		for(int i=0;i<N;i++)dis[i][i]=0;
		int mnw=INF;
		for(int k=0;k<N;k++)
		{
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<k;j++)
				{
					//if(i==j)continue;
					if(mnw>mp[k][i]+dis[i][j]+mp[j][k])
					{
						mnw=mp[k][i]+dis[i][j]+mp[j][k];
						//printf("%d %d %d\n",k,i,j);
					}
				}
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		if(mnw<(int)1e8)printf("%d\n",mnw);
		else printf("-1\n");
	}
	return 0;
}

