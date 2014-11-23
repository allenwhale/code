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
#define PPF(a) push_front(a)
#define PF() pop_front()
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
ll c[21][21][21+10];
ll sum[21][21][21][21][21+10];
ll _sum[21][21+10];
int N1,N2,N3;
inline ll cnt(int y,int x1,int x2)
{
	return _sum[x2][y]-_sum[x1-1][y];
}
void pre()
{
	for(int i=1;i<=N1;i++)
	{
		for(int y=1;y<=N3;y++)
		{
			for(int x=1;x<=N2;x++)
			{
				_sum[x][y]=_sum[x-1][y]+c[i][x][y];
			}
		}
		for(int x1=1;x1<=N2;x1++)
		{
			for(int y1=1;y1<=N3;y1++)
			{
				for(int x2=x1;x2<=N2;x2++)
				{
					for(int y2=y1;y2<=N3;y2++)
					{
						sum[i][x1][y1][x2][y2]=
							sum[i][x1][y1][x2][y2-1]+cnt(y2,x1,x2);
						//printf(" %d %d %d %d %d %I64d\n",i,x1,y1,x2,y2,sum[i][x1][y1][x2][y2]);
					}
				}
			}
		}
	}
}
ll solve()
{
	ll ans=-(ll)INF*(ll)INF;
	//puts("in");
	//printf("%d %d %d\n",N1,N2,N3);
	for(int x1=1;x1<=N2;x1++)
	{
		//puts("in1");
		for(int y1=1;y1<=N3;y1++)
		{
			//puts("in2");
			for(int x2=x1;x2<=N2;x2++)
			{
				for(int y2=y1;y2<=N3;y2++)
				{
					//puts("aaa");
					ll tmp=0ll;
					for(int i=1;i<=N1;i++)
					{
						tmp+=sum[i][x1][y1][x2][y2];
						//printf("%d %d %d %d %d %I64d\n",i,x1,y1,x2,y2,sum[i][x1][y1][x2][y2]);
						//printf(__lld"\n",tmp);
						ans=max(ans,tmp);
						if(tmp<0)tmp=0;
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N1,&N2,&N3);
		//printf("%d %d %d\n",N1,N2,N3);
		for(int i=1;i<=N1;i++)
		{
			for(int j=1;j<=N2;j++)
			{
				for(int k=1;k<=N3;k++)
				{
					scanf(__lld,&c[i][j][k]);
				}
			}
		}
		pre();		
		printf(__lld"\n",solve());
		if(T)puts("");
	}
	return 0;
}

