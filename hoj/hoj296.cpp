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
int A[400];
int m[10];
int ans=0;
int dp[50][50][50][50];
int dfs(int a,int b,int c,int d)
{
	int &tmp=dp[a][b][c][d];
	if(!a&&!b&&!c&&!d)return tmp=0;
	if(tmp!=-1)return tmp;
	if(a)tmp=max(tmp,dfs(a-1,b,c,d));
	if(b)tmp=max(tmp,dfs(a,b-1,c,d));
	if(c)tmp=max(tmp,dfs(a,b,c-1,d));
	if(d)tmp=max(tmp,dfs(a,b,c,d-1));
	return tmp=tmp+A[a*1+b*2+c*3+d*4];
}
int main()
{
	MS(dp,-1);
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<M;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		m[tmp]++;
	}
	printf("%d\n",A[0]+dfs(m[1],m[2],m[3],m[4]));
	return 0;
}

