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
struct E
{
	int to,c;
	E(){}
	E(int _t,int _c)
	{
		to=_t,c=_c;
	}
};
vector<E>vc[100010];
bool ind[100010];
int N;
int d=0;
int Pi=1;
void dfs(int x,int dth,int px)
{
	if(d<dth)
	{
		d=dth;
		Pi=x;
	}
	foreach(it,vc[x])
	{
		if(it->to==px)continue;
		dfs(it->to,dth+it->c,x);
	}
}

bool dfs2(int x,int dth,int px)
{
	if(dth==d)
	{
		Pi=x;
		return ind[x]=true;
	}
	bool flag=false;
	foreach(it,vc[x])
	{
		if(it->to==px)continue;
		flag|=dfs2(it->to,dth+it->c,x);
	}
	return ind[x]=flag;
}
int ans=INF,C=-1;
void dfs3(int x,int dth,int px)
{
	if(ind[x])
	{
		//printf(" %d %d\n",x,dth);
		if(ans>abs(d-2*dth))
		{
			ans=abs(d-2*dth);
			C=x;
		}
	}
	foreach(it,vc[x])
	{
		if(it->to==px)continue;
		dfs3(it->to,dth+it->c,x);
	}
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc[a].PB(E(b,c));
		vc[b].PB(E(a,c));
	}
	dfs(Pi,0,Pi);
	dfs(Pi,0,Pi);
	//printf("%d\n",d);
	dfs2(Pi,0,Pi);
	dfs3(Pi,0,Pi);
	printf("%d\n",C);
	return 0;
}

