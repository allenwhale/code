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
int N,M;
struct edge
{
	int to,w;
	edge(){}
	edge(int _t,int _w):to(_t),w(_w){}
};
vector<edge>vc[1010];
int dist[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++)vc[i].clear();
		MS(dist,0x3f);
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			vc[a].push_back(edge(b,c));
			//vc[b].push_back(edge(a,c));
		}
		dist[0]=0;
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<N;j++)
			{
				foreach(it,vc[j])
				{
					if(dist[it->to]>dist[j]+it->w)
					{
						dist[it->to]=dist[j]+it->w;
					}
				}
			}
		}
		bool ans=false;
		for(int i=0;i<N;i++)
		{
			foreach(it,vc[i])
			{
				if(dist[it->to]>dist[i]+it->w)ans=true;
			}
		}
		if(ans)puts("possible");
		else puts("not possible");
		
	}
	return 0;
}

