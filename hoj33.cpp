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
int s[310][310],N,sum[310][310];
int main()
{
	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(i==1&&j==1)scanf("%d",&s[1][1]);
				else if(j==1)s[i][j]=s[1][1]+i;
				else s[i][j]=((s[i][j-1]*17)%103)*(((i+j)&1)?-1:1);
			}
		}
		for(int j=1;j<=N;j++)
		{
			for(int i=1;i<=N;i++)
			{
				sum[j][i]=sum[j][i-1]+s[i][j];
			}
		}
		int ans=-INF;
		for(int i=1;i<=N;i++)
		{
			for(int j=i;j<=N;j++)
			{
				int tsum=0;
				for(int k=1;k<=N;k++)
				{
					tsum+=sum[k][j]-sum[k][i-1];
					if(ans<tsum)ans=tsum;
					if(tsum<0)tsum=0;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

