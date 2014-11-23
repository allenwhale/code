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
int p[300100];
int ac[300010][20];
int dis[300010];
int sroot=1;
int N=1;
inline void update(int x)
{
	dis[x]=dis[p[x]]+1;
	ac[x][0]=p[x];
	for(int i=1;i<20&&(1<<i)<=dis[x];i++)
	{
		ac[x][i]=ac[ac[x][i-1]][i-1];
	}
}
inline int LCA(int x,int y)
{
	//puts("find lca");
	while(x!=y)
	{
		//printf("  %d %d\n",x,y);
		//system("pause");
		if(dis[x]==dis[y])x=p[x],y=p[y];
		else if(dis[x]<dis[y])y=p[y];
		else x=p[x];
	}
	return x;
}
inline int climb(int x,int k)
{
	for(int i=18;i>=0;i--)
	{
		if(k>=(1<<i))
		{
			x=ac[x][i];
			k-=1<<i;
		}
	}
	return x;
}
int main()
{
	int T;
	scanf("%d",&T);
	p[1]=1;
	for(int i=0;i<20;i++)ac[1][i]=1;
	dis[1]=0;
	int d=0;
	while(T--)
	{
		//printf(" %d\n",T);
		char tmp[2];
		scanf("%s",tmp);
		if(tmp[0]=='a')
		{
			int x;
			scanf("%d",&x);
			x-=d;
			p[++N]=x;
			update(N);
		}
		else if(tmp[0]=='r')
		{
			int x;
			scanf("%d",&x);
			x-=d;
			sroot=x;
		}
		else if(tmp[0]=='q')
		{
			int u,v,k;
			scanf("%d %d",&u,&k);
			v=sroot;
			u-=d,k-=d;
			//printf("%d %d %d\n",u,v,k);
			if(v==u)
			{
				printf("%d\n",d=u);
				continue;
			}
			int lca=LCA(u,v);
			//printf("lca=%d\n",lca);
			int du=dis[u]-dis[lca],dv=dis[v]-dis[lca];
			int f;
			if((k/(du+dv))&1)f=v;
			else f=u;
			k=k-(k/(du+dv))*(du+dv);
			if(f==v&&k>dv)
			{
				f=u;k=dv+du-k;
			}
			else if(f==u&&k>du)
			{
				f=v;k=dv+du-k;
			}
			//printf("f=%d k=%d\n",f,k);
			printf("%d\n",d=climb(f,k));
		}
	}
	return 0;
}

