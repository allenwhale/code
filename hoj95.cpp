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
int N,M;
vector<int>vc[200010];
bool vis[200010];
int p[200010];
void dfs(int x,int k)
{
	vis[x]=true;
	p[x]=k;
	foreach(it,vc[x])
	{
		if(vis[*it]==false)dfs(*it,k^1);
	}
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].PB(b);
		vc[b].PB(a);
	}
	MS(vis,false);
	for(int i=1;i<=N;i++)
	{
		if(SIZE(vc[i])==0)
		{
			puts("NIE");
			return 0;
		}
		if(vis[i]==false)dfs(i,1);
	}
	puts("TAK");
	for(int i=1;i<=N;i++)
	{
		if(p[i])puts("K");
		else puts("S");
	}
	return 0;
}

