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
vector<int>vc[50010];
int N,M;
bool vis[50010];
int f[50010],pa[50010],son[50010];
int a[50010],g[50010];
void dfs(int x)
{
	vis[x]=true;
	if(x!=1)f[x]=1;
	son[x]=0;
	foreach(it,vc[x])
	{
		if(!vis[*it])
		{
			pa[*it]=x;
			dfs(*it);
			f[x]+=f[*it];
			son[x]++;
		}
	}
	f[x]-=(son[x]+(x!=1))/2;
}
int maxg=0;
bool check(int m,int t)
{
	int l=0,r=t-1;
	while(l<=r)
	{
		if(l==m)l++;
		if(r==m)r--;
		if(a[l]+a[r]>maxg)return false;
		l++,r--;
	}
	return true;
}
bool dfs2(int x)
{
	foreach(it,vc[x])
	{
		if(*it!=pa[x])
			if(!dfs2(*it))return false;
	}
	int tot=0;
	foreach(it,vc[x])
	{
		if(*it!=pa[x])a[tot++]=g[*it];
	}
	if(x==1&&((tot&1)==0))
	{
		sort(a,a+tot);
		int l=0,r=tot-1;
		g[x]=0;
		while(l<r)g[x]=max(g[x],a[l++]+a[r--]);
		if(g[x]>maxg)return 0;
		return true;
	}
	if((tot&1)==0)a[tot++]=0;
	sort(a,a+tot);
	int l=0,r=tot-1;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid,tot))ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==-1)return false;
	g[x]=a[ans]+(x!=1);
	return g[x]<=maxg;
}
int main()
{
	scanf("%d",&N);
	MS(vis,false);
	for(int i=0;i<N-1;i++)
	{
		int aa,b;
		scanf("%d %d",&aa,&b);
		vc[aa].PB(b);
		vc[b].PB(aa);
	}
	dfs(1);
	int l=1,r=N-1;
	int ans=-1;
	while(l<=r)
	{
		int mid=maxg=(l+r)>>1;
		if(dfs2(1))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d %d\n",f[1],ans);
	return 0;
}

