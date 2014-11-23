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
vector<int>num[50010];
bool is[50010];
int sum[50010];
int main()
{
	for(int i=2;i<=50000;i++)
	{
		if(is[i]==false)
		{
			num[i].PB(i);
			for(int j=i+i;j<=50000;j+=i)
			{
				is[j]=1;
				num[j].PB(i);
			}
		}
	}
	for(int i=2;i<=50000;i++)
	{
		int add=1;
		foreach(it,num[i])
			add*=(*it);
		sum[i]=sum[i-1];
		if(i==add)
		{
			if(SIZE(num[i])&1)sum[i]--;
			else sum[i]++;
		}
	}
	int a,b,c;
	int T;
	scanf("%d\n",&T);
	while(T--)
	{
		scanf("%d %d %d",&a,&b,&c);
		//printf("%d %d %d\n",a,b,c);
		ll ans;
		if(a>b)swap(a,b);
		int n=a/c,m=b/c;
		//printf("%d %d\n",n,m);
		ans=(ll)n*m;
		for(int i=2;i<=n;i++)
		{
			int A,B;
			A=m/i;B=n/i;
			A=m/A;B=n/B;
			A=min(A,B);
			//A=min(A,n);
			ans+=(ll)(n/i)*(ll)(m/i)*(ll)(sum[A]-sum[i-1]);
			i=A;
		}
		printf(__lld"\n",ans);
	}
	return 0;
}


