#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <complex>
#include <functional>
//#include<bits/stdc++.h>
//#include<ext/rope>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
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
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
//typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>tmap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>tset;
inline int getint()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	int x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
inline ll getll()
{
	char s,d;
	while(s=getchar(),!(('0'<=s&&s<='9')||(s=='-')));
	ll x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
struct P
{
	int x,y;
	P(){}
	P(int _x,int _y)
	{
		x=_x,y=_y;
	}
	bool operator < (const P &n)const
	{
		if(n.x==x)return n.y>y;
		return n.x>x;
	}
}p[5010];
int R,C,N;
bool mp[5010][5010];
bool inmap(int x,int y)
{
	return x>0&&y>0&&x<=R&&y<=C;
}
int getsum(int i,int j)
{
	int dx=p[j].x-p[i].x;
	int dy=p[j].y-p[i].y;
	int ans=1;
	int nx=p[i].x,ny=p[i].y;
	while(true)
	{
		nx+=dx,ny+=dy;
		if(inmap(nx,ny)==false)break; 
		if(mp[nx][ny]==false)
		{
			ans=0;
			break;
		} 
		ans++;
	}
	return ans;
}

int main()
{
	MS(mp,false);
	R=getint();C=getint();N=getint();
	for(int i=0;i<N;i++)
	{
		p[i].x=getint();p[i].y=getint();
		mp[p[i].x][p[i].y]=true;
	}
	sort(p,p+N);
//	puts("");
//	for(int i=0;i<N;i++)
//	{
//		printf("%d %d\n",p[i].x,p[i].y);
	//}
	//puts("");
	int ans=2;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			int dx=p[j].x-p[i].x,dy=p[j].y-p[i].y;
			if(p[i].x+(ans-1)*dx>=R)break;
			if(inmap(p[i].x-dx,p[i].y-dy))continue;
			if(inmap(p[i].x+(ans-1)*dx,p[i].y+(ans-1)*dy)==false)continue;
			ans=max(ans,getsum(i,j));
			//printf("%d %d %d\n",i,j,getsum(i,j));
		}
	}
	//printf("%d\n",ans);
	if(ans<3)puts("0");
	else printf("%d\n",ans);
	return 0;
}


