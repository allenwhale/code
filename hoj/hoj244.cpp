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
int L,W,N,K;
int mp[3][350][350];
int s[350][350];
#define CNT(a,b,c,d) (s[a][b]-s[c][b]-s[a][d]+s[c][d])
int cnt(int idx,int n)
{
	//printf("cnt %d\n",idx);
	int x=INF;
	for(int i=0;i<=n;i++)
	{
		int j=0,k=0;
		while(true)
		{
			//printf("%d %d\n",j,k);
			int r=s[n][k]-s[n][j]-s[n-i][k]+s[n-i][j];
			if(r<K)
			{
				if(k++==W)break;
			}
			else if(r==K)
			{
				x=min(x,2*(i+k-j));
				j++;
			}
			else if(r>K)
				j++;
		}
	}
	return x;
}
vector<int> make(int idx)
{
	//printf("make %d\n",idx);
	for(int i=1;i<=L;i++)
	{
		for(int j=1;j<=W;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[idx][i][j];
		}
	}
	vector<int>vc;
	vc.resize(L+1);
	vc[0]=INF;
	for(int i=1;i<=L;i++)
		vc[i]=min(vc[i-1],cnt(idx,i));
	return vc;
}
int inner(vector<int>::IT a,vector<int>::IT b,vector<int>::IT c)
{
	int init=INT_MAX;
	for(;a!=b;a++,c++)
	{
		//printf("%d %d\n",*a,*c);
		init=min(init,*a+*c);
	}
	return init;
}
int rev(int idx)
{
	//printf("rev %d\n",idx);
	for(int i=1;i<=L;i++)
		copy(mp[idx][i]+1,mp[idx][i]+W+1,mp[2][L-i+1]+1);
	//puts("copy");
	vector<int>a(make(idx)),b(make(2));
	reverse(b.begin(),b.begin()+1+L);
	return inner(a.begin(),a.begin()+L+1,b.begin());
}
int main()
{
	L=getint();
	W=getint();
	N=getint();
	K=getint();
	MS(mp,0);
	MS(s,0);
	for(int i=0;i<N;i++)
		mp[0][getint()][getint()]++;
	for(int i=1;i<=L;i++)
	{
		for(int j=1;j<=W;j++)
		{
			mp[1][j][i]=mp[0][i][j];
		}
	}
	int r=min(rev(1),rev(0));
	if(r>=INF)puts("NO");
	else printf("%d\n",r);
	return 0;
}


