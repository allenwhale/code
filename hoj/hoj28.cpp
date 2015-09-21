#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
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
int N,K,P;
int w[500010],b[100010],n[500010];
int main()
{
	scanf("%d %d %d",&N,&K,&P);
	for(int i=1;i<=P;i++)
		scanf("%d",&w[i]);
	fill(b,b+N+1,P+1);
	for(int i=P;i>=1;i--)
	{
		n[i]=b[w[i]];
		b[w[i]]=i;
	}
	set<pI>st;
	int ans=0;
	for(int i=1;i<=P;i++)
	{
		set<pI>::iterator it=st.find(MP(-b[w[i]],w[i]));
		//printf("%d %d\n",b[w[i]],w[i]);
		if(it==st.end())
		{
			//printf("  %d\n",i);
			
			if(SIZE(st)==K)st.erase(st.begin()),ans++;;
			b[w[i]]=n[b[w[i]]];
			st.insert(MP(-b[w[i]],w[i]));
		}
		else
		{
			st.erase(MP(-b[w[i]],w[i]));
			b[w[i]]=n[b[w[i]]];
			st.insert(MP(-b[w[i]],w[i]));
		}
	}
	printf("%d\n",ans);
	return 0;
}

