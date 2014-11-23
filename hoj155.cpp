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
struct H
{
	int x1,x2,y;
	H(){}
	H(int _1,int _2,int _y)
	{
		x1=_1,x2=_2,y=_y;
	}
}h[300];
struct V
{
	int x,y1,y2;
	V(){}
	V(int _x,int _1,int _2)
	{
		x=_x,y1=_1,y2=_2;
	}
}v[300];
bool iscross(H a,V b)
{
	if(a.y>b.y2||a.y<b.y1)return false;
	if(b.x<a.x1||b.x>a.x2)return false;
	return true;
}
int hn=0,vn=0;
vector<int>vc[300];
int mh[300],mv[300];
bool vis[300];
bool dfs(int x)
{
	foreach(it,vc[x])
	{
		if(!vis[*it])
		{
			vis[*it]=true;
			if(mv[*it]==-1||dfs(mv[*it]))
			{
				mh[x]=*it,mv[*it]=x;
				return true;
			}
		}
	}
	return false;
}
int match()
{
	MS(mh,-1);
	MS(mv,-1);
	int m=0;
	for(int i=0;i<hn;i++)
	{
		if(mh[i]==-1)
		{
			MS(vis,false);
			if(dfs(i))m++;
		}
	}
	return m;
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==x2)
		{
			v[vn++]=V(x1,min(y1,y2),max(y1,y2));
		}
		else if(y1==y2)
		{
			h[hn++]=H(min(x1,x2),max(x1,x2),y1);
		}
	}
	for(int i=0;i<hn;i++)
	{
		for(int j=0;j<vn;j++)
		{
			if(iscross(h[i],v[j]))vc[i].PB(j);
		}
	}
	printf("%d\n",N-match());
	return 0;
}

