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
int N;
char s1[1000010],s2[1000010];
stack<int>s[30];
int bit[1000010];
#define lb(x) ((x)&(-(x)))
inline void add(int x,int v)
{
	for(int i=x;i<=N;i+=lb(i))
	{
		bit[i]+=v;
	}
}
inline int sum(int x)
{
	int res=0;
	for(int i=x;i>0;i-=lb(i))
	{
		res+=bit[i];
	}
	return res;
}
int main()
{
	scanf("%d",&N);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=1;i<=N;i++)
	{
		s[s1[i]-'A'].push(i);
		add(i,1);
	}
	ll ans=0;
	for(int i=N;i>0;i--)
	{
		int x=s[s2[i]-'A'].top();
		s[s2[i]-'A'].pop();
		ans+=(ll)i-sum(x);
		add(x,-1);
	}
	printf(__lld"\n",ans);
	return 0;
}

