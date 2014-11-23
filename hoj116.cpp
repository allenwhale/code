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
char mp[1010][1010];
int up[1010][1010];
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%s",mp[i]);
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(mp[i][j]=='0')up[i][j]=0;
			else
			{
				if(!i||!j)up[i][j]=1;
				else up[i][j]=min(min(up[i-1][j],up[i][j-1]),up[i-1][j-1])+1;
			}
			ans+=up[i][j];
		}	
	}
	printf("%d\n",ans);
	return 0;
}

