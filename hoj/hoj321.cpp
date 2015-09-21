#include<bits/stdc++.h>
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
struct P
{
	int time,num;
	P(){}
	P(int _t,int _n)
	{
		time=_t,num=_n;
	}
	bool operator < (const P &n)const
	{
		if(n.time==time)return n.num<num;
		return n.time<time;
	}
};
int N,M;
int room[1010];
int num[1010];
int now[1010];
int r[1010][1010];
int main()
{
	priority_queue<P>pq;
	N=getint();M=getint();
	for(int i=0;i<N;i++)
	{
		int in=getint();
		pq.push(P(in,i));
		num[i]=getint();
		for(int j=0;j<num[i];j++)
		{
			r[i][j]=getint();
		}
	}
	int mx=0;
	while(!pq.empty())
	{
		P out=pq.top();pq.pop();
		int nx=r[out.num][now[out.num]++];
		out.time=room[nx]=max(out.time,room[nx])+1;
		mx=max(out.time,mx);
		if(now[out.num]<num[out.num])
		{
			pq.push(out);
		}
	}
	printf("%d\n",mx);
	return 0;
}


