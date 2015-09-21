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
struct node
{
	int x,y,z,num;
	node(){}
	inline node(int _x,int _y,int _z)
	{
		x=_x,y=_y,z=_z;
	}
	inline node operator - (const node &n)const
	{
		return node(this->x-n.x,this->y-n.y,this->z-n.z);
	}
	inline int Abs()
	{
		return min(min(abs(this->x),abs(this->y)),abs(this->z));
	}
}s[100010],r[300010];
inline int cmp1(node a,node b)
{
	return a.x<b.x;
}
inline int cmp2(node a,node b)
{
	return a.y<b.y;
}
inline int cmp3(node a,node b)
{
	return a.z<b.z;
}
int p[100010];
void init()
{
	for(int i=0;i<100010;i++)p[i]=i;
}
inline int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
inline void U(int a,int b)
{
	p[find(a)]=find(b);
}
int main()
{
	init();
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].z);
		s[i].num=i;
	}
	int cnt=0;
	sort(s,s+N,cmp1);
	for(int i=0;i<N-1;i++)
	{
		r[cnt++]=node(s[i].num,s[i+1].num,(s[i]-s[i+1]).Abs());
	}
	sort(s,s+N,cmp2);
	for(int i=0;i<N-1;i++)
	{
		r[cnt++]=node(s[i].num,s[i+1].num,(s[i]-s[i+1]).Abs());
	}
	sort(s,s+N,cmp3);
	for(int i=0;i<N-1;i++)
	{
		r[cnt++]=node(s[i].num,s[i+1].num,(s[i]-s[i+1]).Abs());
	}
	sort(r,r+cnt,cmp3);
	int tmp=N;
	int ans=0;
	for(int i=0;tmp>0&&i<cnt;i++)
	{
		int x=find(r[i].x);
		int y=find(r[i].y);
		if(x==y)continue;
		U(x,y);
		tmp--;
		ans+=r[i].z;
	}
	printf("%d\n",ans);
	return 0;
}

