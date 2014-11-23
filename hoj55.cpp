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
int N;
vector<int>vc[100010],rvc[100010],st;
int scc[100010];
int scci[100010],scco[100010];
bool vis[100010];
void dfs(int x)
{
	vis[x]=true;
	foreach(it,vc[x])
	{
		if(vis[*it]==false)dfs(*it);	
	}
	st.PB(x);
}
void dfs2(int x,int c)
{
	vis[x]=true;
	scc[x]=c;
	foreach(it,rvc[x])
	{
		if(vis[*it]==false)dfs2(*it,c);
	}
}

int SCC()
{
	MS(vis,false);
	for(int i=1;i<=N;i++)
		if(vis[i]==false)dfs(i);
	MS(vis,false);
	int c=0;
	for(int i=N-1;i>=0;i--)
		if(vis[st[i]]==false)dfs2(st[i],c++);
	return c;
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		while(tmp!=0)
		{
			vc[i].PB(tmp);
			rvc[tmp].PB(i);
			scanf("%d",&tmp);
		}		
	}
	int c=SCC();
	if(c==1)
	{
		printf("1\n0\n");
		return 0;
	}
	for(int i=1;i<=N;i++)
	{
		foreach(it,vc[i])
		{
			if(scc[i]!=scc[*it])
			{
				scci[scc[*it]]++;
				scco[scc[i]]++;
			}
		}
	}
	int cnti=0,cnto=0;
	for(int i=0;i<c;i++)
	{
		if(scci[i]==0)cnti++;
		if(scco[i]==0)cnto++;
	}
	printf("%d\n%d\n",cnti,max(cnti,cnto));
	return 0;
}


