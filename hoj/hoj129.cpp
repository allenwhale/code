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
int N,M;
int mp[3010][3010];
int sum[3010][3010];
int l[3010],r[3010],L[3010],R[3010],up[3010];
bool ok[3010];
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int lll=0;
		for(int j=0;j<M;j++)
		{
			if(mp[i][j]==1)l[j]=lll;
			else l[j]=j,lll=j+1;
		}
		int rr=M;
		for(int j=M-1;j>0;j--)
		{
			if(mp[i][j]==1)r[j]=rr;
			else r[j]=j,rr=j;
		}
		for(int j=0;j<M;j++)
			printf(" %d",l[j]);
		puts("");
		for(int j=0;j<M;j++)
		{
			if(mp[i][j]==0)
			{
				ok[j]=false;
				up[j]=0;
			}
			else
			{
				int tl,tr;
				if(ok[j])tl=max(L[j],l[j]),tr=min(R[j],r[j]);
				else tl=l[j],tr=r[j];
				up[j]++;
				printf("%d %d %d %d\n",j,up[j],tl,tr);
				ans=max(ans,up[j]*(tr-tl));
				L[j]=tl,R[j]=tr;
				ok[j]=true;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

