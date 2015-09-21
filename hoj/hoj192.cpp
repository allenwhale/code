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
#define MAX3(a,b,c) max((a),max((b),(c)))
#define MAX4(a,b,c,d) max(max((a),(b)),max((c),(d)))
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
int N;
int mp[310][310];
int dp[2][310][310];
int main()
{
	N=getint();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			mp[i][j]=getint();
		}
	}
	fill((int*)dp,(int*)dp+310*310*2,-1e9);
	int flag=0;
	dp[flag^1][1][1]=mp[0][0];
	for(int k=1;k<=2*(N-1);k++,flag^=1)
	{
		for(int i=1;i-1<=k&&i-1<N;i++)
		{
			for(int j=1;j-1<=k&&j-1<N;j++)
			{
				if(i>j)continue;
				if(i==j)
				{
					dp[flag][i][j]=MAX3(
						dp[flag^1][i][j],
						dp[flag^1][i-1][j],
						dp[flag^1][i-1][j-1]
					)+mp[i-1][k-i+1];
					//printf("  %d %d %d\n",dp[k-1][i][j],
				//		dp[k-1][i-1][j],
					//	dp[k-1][i-1][j-1]);
					//printf("%d\n",mp[i-1][k-i+1]);
				}
				else
				{
					dp[flag][i][j]=MAX4(
						dp[flag^1][i][j],
						dp[flag^1][i-1][j],
						dp[flag^1][i][j-1],
						dp[flag^1][i-1][j-1]
					)+mp[i-1][k-i+1]+mp[j-1][k-j+1];
					//printf("  %d %d %d %d\n",dp[k-1][i][j],
					//	dp[k-1][i-1][j],
					///	dp[k-1][i][j-1],
					//	dp[k-1][i-1][j-1]);
					//printf(" %d %d %d %d\n",i,mp[i][k-i],j,mp[j][k-j]);
				}
				//printf("%d %d %d %d\n",k,i,j,dp[k][i][j]);
			}
		}
	}
	printf("%d\n",dp[flag^1][N][N]);
	return 0;
}


