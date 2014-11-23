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
int N,M,dist[20][20],d[20];
int dp[(1<<17)+10];
int match(int s)
{
	//printf("%d\n",s);
	//system("pause");
	int &tmp=dp[s];
	if(tmp!=-1)return tmp;
	if(s==0)return tmp=0;
	tmp=INF;
	for(int i=1;i<=N;i++)
	{
		if((s&(1<<i))==0)continue;
		for(int j=1;j<=N;j++)
		{
			if(i==j||(s&(1<<j))==0)continue;
			//printf(" %d %d %d\n",i,j,1<<i | 1<<j);
			tmp=min(tmp,dist[i][j]+match(s^((1<<i)|(1<<j))));
		}
	}
	return tmp;
}
int main()
{
	while(~scanf("%d",&N)&&N&&~scanf("%d",&M))
	{
		MS(dist,0x3f);MS(d,0);
		int sum=0;
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			dist[a][b]=dist[b][a]=min(dist[a][b],c);
			d[a]++,d[b]++;
			sum+=c;
		}
		for(int k=1;k<=N;k++)
		{
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=N;j++)
				{
					if(i==k||i==j||j==k)continue;
					dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		int sta=0;
		for(int i=1;i<=N;i++)
			sta|=((d[i]&1)<<i);
		//system("pause");
		MS(dp,-1);
		printf("%d\n",sum+match(sta));
	}
	return 0;
}

