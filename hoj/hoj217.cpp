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
int N,K,A,B;
char s[5010];
int num[5010];
int dp[510][5010],ju[510][5010];
int main()
{
	int T=getint();int t=1;
	while(T--)
	{
		MS(dp,0);
		printf("Case #%d:\n",t++);
		N=getint();K=getint();
		A=getint();B=getint();
		scanf("%s",s);
		for(int i=0;i<N;i++)
		{
			num[i]=getint();
			if(i+1>=A&&i+1<=B)
			{
				dp[1][i]=num[i];
				ju[1][i]=i+1;
			}
		}
		for(int i=2;i<=K;i++)
		{
			deque<int>dq;
			for(int j=0;j<N;j++)
			{
				if(j-A<0||dp[i-1][j-A]==0);
				else
				{
					while(!dq.empty()&&dp[i-1][dq.back()]<=dp[i-1][j-A])dq.pop_back();
					dq.push_back(j-A);
				}
				while(!dq.empty()&&j-dq.front()>B)dq.pop_front();
				//printf("%d\n",SIZE(dq));
				if(dq.empty())dp[i][j]=0;
				else 
				{
					dp[i][j]=dp[i-1][dq.front()]+i*num[j];
					ju[i][j]=j-dq.front();
				}
				//printf("%d %d %d\n",i,j,dp[i][j]);
			}
		}
		if(dp[K][N-1]==0)puts("Sorry, you're milk cheese.");
		else
		{
			printf("%d\n",dp[K][N-1]);
			deque<deque<char> >c;
			int n=N-1;
			for(int i=K;i;i--)
			{
				deque<char>tmp;
				int cnt=ju[i][n];
				for(int j=0;j<cnt;j++,n--)
				{
					tmp.push_front(s[n]);
				}
				c.push_front(tmp);
			}
			for(int i=0;i<K;i++)
			{
				deque<char> tmp=c[i];
				foreach(it,tmp)
				{
					printf("%c",*it);
				}
				puts("");
			}
		}
	}
	return 0;
}


