#include<bits/stdc++.h>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>tmap;
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
int N,M,K;
struct E
{
	int a,b;
	E(){}
	E(int _a,int _b)
	{
		a=_a,b=_b;
	}
}e1[100010],e2[100010],e3[100010];
int p[20010];
int cnt1=0,cnt2=0,cnt3=0;
void init()
{
	for(int i=0;i<20010;i++)p[i]=i;
}
int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
void U(int a,int b)
{
	p[find(a)]=find(b);
}
int main()
{
	init();
	N=getint();M=getint();K=getint();
	int tmp=K;
	for(int i=0;i<M;i++)
	{
		int a=getint(),b=getint(),c=getint();
		if(c==1)
		{
			e1[cnt1++]=E(a,b);
		}
		else
		{
			e2[cnt2++]=E(a,b);
		}
	}
	if(K>=N||cnt2<K)
	{
		puts("no solution");
		return 0;
	}
	for(int i=0;i<cnt1;i++)
		U(e1[i].a,e1[i].b);
	for(int i=0;i<cnt2;i++)
	{
		if(find(e2[i].a)!=find(e2[i].b))
		{
			U(e2[i].a,e2[i].b);
			e3[cnt3++]=e2[i];
		}
	}
	if(cnt3>K)
	{
		puts("no solution");
		return 0;
	}
	init();
	for(int i=0;i<cnt3;i++)
	{
		U(e3[i].a,e3[i].b);
	}
	if(cnt3<K)
	{
		for(int i=0;i<cnt2;i++)
		{
			if(find(e2[i].a)!=find(e2[i].b))
			{
				U(e2[i].a,e2[i].b);
				e3[cnt3++]=e2[i];
				if(cnt3==K)break;
			}
		}
	}
	if(cnt3!=K)
	{
		puts("no solution");
		return 0;
	}
	for(int i=0;i<cnt1;i++)
	{
		if(find(e1[i].a)!=find(e1[i].b))
		{
			e3[cnt3++]=e1[i];
			U(e1[i].a,e1[i].b);
			if(cnt2==N-1)break;
		}
	}
	for(int i=0;i<cnt3;i++)
	{
		printf("%d %d ",e3[i].a,e3[i].b);
		if(i<K)printf("0\n");
		else printf("1\n");
	}
	return 0;
}


