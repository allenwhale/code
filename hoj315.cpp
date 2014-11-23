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
int N;
struct W
{
	int l,r;
	int mid;
}w[2000010];
struct R
{
	int n,tf;
	R(){}
	R(int _n,int _t)
	{
		n=_n,tf=_t;
	}
	bool operator < (const R &a)const
	{
		return n>a.n;
	}
};
struct L
{
	int n,tf;
	L(){}
	L(int _n,int _t)
	{
		n=_n,tf=_t;
	}
	bool operator < (const L &a)const
	{
		return n<a.n;
	}
};
priority_queue<L>lpq;
priority_queue<R>rpq;
ll lpq_sumr=0,rpq_suml=0;
int lpq_szr=0,rpq_szl=0;
int getmid()
{
	return lpq.top().n;
}
void push(int x,int t)
{
	if(SIZE(lpq)==0&&SIZE(rpq)==0)
	{
		lpq.push(L(x,t));
		if(t==1)lpq_sumr+=x,lpq_szr++;
		return;
	}
	int mid=getmid();
	if(x>=mid)
	{
		rpq.push(R(x,t));
		if(t==0)rpq_szl++,rpq_suml+=x;
	}
	else 
	{
		lpq.push(L(x,t));
		if(t==1)lpq_szr++,lpq_sumr+=x;
	}
	if(SIZE(lpq)>SIZE(rpq)+1)
	{
		L tmp=lpq.top();
		rpq.push(R(tmp.n,tmp.tf));
		lpq.pop();
		if(tmp.tf==0)rpq_suml+=tmp.n,rpq_szl++;
		else lpq_sumr-=tmp.n,lpq_szr--;
	}
	if(SIZE(rpq)>SIZE(lpq))
	{
		R tmp=rpq.top();
		lpq.push(L(tmp.n,tmp.tf));
		rpq.pop();
		if(tmp.tf==0)rpq_suml-=tmp.n,rpq_szl--;
		else lpq_sumr+=tmp.n,lpq_szr++;
	}
}
ll count(int idx,int n)
{
	return (ll)idx*lpq_szr-lpq_sumr+rpq_suml-(ll)rpq_szl*idx;
	int res=0;
	for(int i=0;i<=n;i++)
	{
		if(w[i].l<=idx&&idx<=w[i].r);
		else if(w[i].l>idx)res+=w[i].l-idx;
		else res+=idx-w[i].r;
	}
	return res;
}
int main()
{

	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&w[i].l,&w[i].r);
		w[i].mid=(w[i].l+w[i].r)>>1;
		push(w[i].l,0);push(w[i].r,1);
		//printf("%d %d %d %d\n",lpq_sumr,lpq_szr,rpq_suml,rpq_szl);
		int m=getmid();
		printf(__lld"\n",count(m,i));
	}
	return 0;
}

