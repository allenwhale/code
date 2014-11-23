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
#define rev(x) ((x)+N+M)
int N,M,K;
int p[400010];
void init()
{
	for(int i=0;i<2*(N+M);i++)
		p[i]=i;
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
	while(~scanf("%d %d %d",&N,&M,&K))
	{
		init();
		for(int i=0;i<K;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			c^=(a&1)&(b&1);
			if(c)U(a,N+b),U(rev(a),rev(N+b));
			else U(a,rev(N+b)),U(rev(a),N+b);
		}
		int tmp=0;
		for(int i=1;i<=N+M;i++)
		{
			if(find(i)==find(rev(i)))
			{
				//puts("0");
				tmp=-1;
				break;
			}
			if(find(i)==i)tmp++;
		}
		if(tmp==-1)
		{
			puts("0");
			continue;
		}
		//printf("tmp %d\n",tmp);
		int ans=1;
		for(int i=1;i<tmp;i++)
		{
			ans*=2;
			ans%=(int)1e9;
		}
		printf("%d\n",ans);
	}
	return 0;
}

