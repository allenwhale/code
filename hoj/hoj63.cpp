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
struct R
{
	int a,b,c,num;
	R(){}
	R(int _a,int _b,int _c,int _N)
	{
		a=_a,b=_b,c=_c,num=_N;
	}
	bool operator < (const R &n)const
	{
		return this->c<n.c;
	};
	bool operator == (const R &n)const
	{
		return this->c==n.c;
	}
};
vector<R>vc;
int N,M;
int p[7010];
void init()
{
	for(int i=0;i<=7001;i++)p[i]=i;
	
}
inline int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
inline void U(int a,int b)
{
	p[find(a)]=find(b);
}
bool ok[300010];
int main()
{
	scanf("%d %d",&N,&M);
	init();
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vc.PB(R(a,b,c,i));
	}
	sort(vc.begin(),vc.end());
	/*
	for(int i=0;i<M;i++)
		printf("  %d %d %d\n",vc[i].a,vc[i].b,vc[i].c);
		*/
	MS(ok,false);
	int tmp=0;
	for(int i=0;i<M&&tmp<N-1;)
	{
		//printf("%d\n",i);
		int n=1;
		while(i+n<M&&vc[i+n-1]==vc[i+n])n++;
		//printf("%d %d %d\n",i,vc[i].c,n);
		for(int j=i;j<i+n;j++)
		{
			int x=find(vc[j].a);
			int y=find(vc[j].b);
			if(x!=y)ok[vc[j].num]=true;
		}
		for(int j=i;j<i+n&&tmp<N-1;j++)
		{
			int x=find(vc[j].a);
			int y=find(vc[j].b);
			if(x!=y)
			{
				//printf(" %d %d\n",vc[j].a,vc[j].b);
				U(x,y),tmp++;
			}
		}
		i+=n;
	}
	for(int i=0;i<M;i++)
	{
		if(ok[i])puts("TAK");
		else puts("NIE");
	}
	return 0;
}

