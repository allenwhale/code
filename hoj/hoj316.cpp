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
int N,K;
struct M
{
	int x,y,z;
	M(){}
	M(int _x,int _y,int _z)
	{
		x=_x,y=_y,z=_z;
	}
	M operator - (const M &n)const
	{
		return M(this->x-n.x,this->y-n.y,this->z-n.z);
	}
	bool operator < (const M &n)const
	{
		return this->z<n.z;
	}
	inline int Abs()const
	{
		return max(max(abs(this->x),abs(this->y)),abs(this->z));
	}
}s[2050],a[4000050];
int p[2050];
void init()
{
	for(int i=0;i<=2000;i++)
	{
		p[i]=i;
	}
}
inline int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
inline void U(int x,int y)
{
	p[find(x)]=find(y);
}
int main()
{
	init();
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].z);
	}
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			a[cnt++]=M(i,j,(s[i]-s[j]).Abs());
		}
	}
	sort(a,a+cnt);

	int tmp=N;
	for(int i=0;tmp>K&&i<cnt;i++)
	{
		//printf("%d %d %d\n",i,a[i].x,a[i].y);
		int x=find(a[i].x);
		int y=find(a[i].y);
		if(x==y)continue;
		U(x,y);
		tmp--;
	}
	int ans=-1;
	for(int i=0;i<cnt;i++)
	{
		//printf("%d %d\n",a[i].x,a[i].y);
		if(find(a[i].x)!=find(a[i].y))
		{
			ans=a[i].z;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

