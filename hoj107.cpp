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
#include <list>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int X[1000010],C[1000010],F[1000010];
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>TSI;
int A,B,m,N;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d",&N,&m,&X[0],&A,&B);
		for(int i=1;i<=N;i++)
		{
			X[i]=(int)(((ll)X[i-1]*A+B)%m);
		}
		for(int i=1;i<=N;i++)
		{
			C[i]=(int)(((ll)X[i]+N-i)%(N-i+1)+1);
		}
		//puts("put");
		TSI s;
		for(int i=0;i<N;i++)
		{
			
		//if(i%10000==0)printf("%d\n",i);
			s[i+1];
		}
		//puts("get");
		for(int i=1;i<=N;i++)
		{
			TSI ::iterator it=s.find_by_order(C[i]-1);
			F[i]=it->FF;
			s.erase(it);
		}
		//puts("ok");
		list<list<int> >l;
		for(int i=1;i<=N;i++)
		{
			if(i==1||F[i]>F[i-1])
				l.push_back(list<int>(1,i));
			else 
				l.back().PB(i);
		}
		ll ans=0;
		for(int i=0;i<N;i++)
		{
			list<list<int> >::iterator a=l.begin(),&b=--l.end();
			ans+=(ll)(i+1)*(a->back());
			a->PPB();
			if(a->empty())
			{
				l.erase(a);
				continue;
			}
			if(F[a->front()]<F[b->back()])
			{
				b->splice(b->end(),*a);
				l.erase(a);
			}
			else
			{
				l.splice(l.end(),l,a);	
			}
		}
		printf(__lld"\n",ans);
	}
	return 0;
}

