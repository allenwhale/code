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
#include <set>
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
struct node
{
	int fa,ls,rs,leaf,tleaf,bleaf,sleaf,deep;
	node()
	{
		fa=ls=rs=leaf=tleaf=bleaf=sleaf=deep=0;
	}
}t[200010];
int N,total;
int small=-1,big=-1;
int ans=0;
bool tf=true;
void dfs1(int x,int d)
{
//	printf(" %d ls %d rs %d\n",x,t[x].ls,t[x].rs);
//	system("pause");
	if(t[x].leaf)
	{
		t[x].deep=d;
		t[x].tleaf=1;
		return;
	}
	t[x].deep=d;
	dfs1(t[x].ls,d+1);dfs1(t[x].rs,d+1);
	t[x].tleaf=t[t[x].ls].tleaf+t[t[x].rs].tleaf;
}
void dfs2(int x)
{
	if(t[x].leaf)
	{
		if(t[x].deep==small)t[x].sleaf=1;
		else t[x].bleaf=1;
		return ;
	}
	dfs2(t[x].ls);dfs2(t[x].rs);
	t[x].sleaf=t[t[x].ls].sleaf+t[t[x].rs].sleaf;
	t[x].bleaf=t[t[x].ls].bleaf+t[t[x].rs].bleaf;
}
void dfs3(int x)
{
	if(t[x].leaf)return;
	if(t[t[x].ls].tleaf==t[t[x].ls].bleaf)dfs3(t[x].rs);
	else if(t[t[x].rs].tleaf==t[t[x].rs].bleaf)ans++,dfs3(t[x].ls);
	else if(t[t[x].rs].tleaf==t[t[x].rs].sleaf)dfs3(t[x].ls);
	else if(t[t[x].ls].tleaf==t[t[x].ls].sleaf)ans++,dfs3(t[x].rs);
	else tf=false;
}
int main()
{
	scanf("%d",&N);
	total=N;
	for(int i=1;i<=N;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if(l==-1)
		{
			t[++total].leaf=1;t[total].fa=i;t[i].ls=total;
		}
		else
		{
			t[i].ls=l,t[l].fa=i;
		}
		if(r==-1)
		{
			t[++total].leaf=1;t[total].fa=i;t[i].rs=total;
		}
		else
		{
			t[i].rs=r,t[r].fa=i;
		}
	}
	dfs1(1,1);
	//puts("dfs1");
	set<int>st;
	for(int i=1;i<=total;i++)
	{
		if(t[i].leaf)
		{
			st.insert(t[i].deep);
			if(SIZE(st)>2)
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(SIZE(st)==1)
	{
		puts("0");
		return 0;
	}
	small=*st.begin();
	if(SIZE(st)==2)big=*st.rbegin();
	if(big-small>1)
	{
		puts("-1");
		return 0;
	}
	dfs2(1);
	//puts("dfs2");
	dfs3(1);
	//puts("dfs3");
	if(tf==false)
	{
		puts("-1");
	}
	else printf("%d\n",ans);
	return 0;
}

