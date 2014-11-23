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
int s[1510];
int dp[2][2][1510];
int N;
int main()
{
	N=getint();
	for(int i=1;i<=N;i++)
	{
		s[i]=getint();
	}
	MS(dp,0);
	if(s[1]>s[2])dp[1][0][2]=1;
	else if(s[1]<s[2])dp[0][0][2]=1;
	int ans=0;
	for(int i=3;i<=N;i++)
	{
		for(int j=i-1;j>0;j--)
		{
			if(s[j]>s[i])dp[1][1][i]+=dp[0][0][j]+dp[0][1][j];
			else if(s[j]<s[i])dp[0][1][i]+=dp[1][0][j]+dp[1][1][j];
			if(s[j]>s[i])dp[1][0][i]++;
			else if(s[j]<s[i])dp[0][0][i]++;
			dp[1][1][i]%=12345;
			dp[0][1][i]%=12345;
			dp[1][0][i]%=12345;
			dp[0][0][i]%=12345;
		}
		ans+=dp[0][1][i]+dp[1][1][i];
		ans%=12345;
	}
	printf("%d\n",ans);
	return 0;
}


