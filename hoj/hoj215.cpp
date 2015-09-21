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
#include <set>
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
struct R
{
	int a,b,c;
	R(){}
	R(int _a,int _b,int _c)
	{
		a=_a,b=_b,c=_c;
	}
	bool operator == (const R &n)const
	{
		return this->c==n.c;
	}
	bool operator < (const R &n)const
	{
		return this->c<n.c;
	}
}r[1010];
int N,M,K;
int p[2][1010];
void init()
{
	for(int i=0;i<1009;i++)p[0][i]=p[1][i]=i;
}
inline int find(int x,int idx)
{
	return x==p[idx][x]?x:p[idx][x]=find(p[idx][x],idx);
}
inline void U(int a,int b,int idx)
{
	p[idx][find(a,idx)]=find(b,idx);
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d %d %d",&N,&M,&K);
		for(int i=0;i<M;i++)
		{
			scanf("%d %d %d",&r[i].a,&r[i].b,&r[i].c);
		}
		sort(r,r+M);
		int tmp=0;
		ll ans=1ll;
		for(int i=0;tmp<N-1&&i<M;)
		{
			//printf("%d\n",i);
			int tp[1010];
			//memcpy(tp,p[1],sizeof(p[1]));
			for(int k=0;k<=N;k++)tp[k]=p[0][k];
			//printf("search\n");
			int n=1;
			while(i+n<M&&r[i+n-1]==r[i+n])n++;
			//printf("%d %d %d\n",i,r[i].c,n);
			int num=0;
			for(int j=i;j<i+n&&tmp<N-1;j++)
			{
				int x=find(r[j].a,0);
				int y=find(r[j].b,0);
				//printf("%d %d %d %d\n",r[j].a,x,r[j].b,y);
				if(x!=y)
				{
					U(x,y,0);
					tmp++;num++;
				}
			}
			//printf("num = %d\n",num);
			int pp=0;
			for(int j=0;j<(1<<n);j++)
			{
				//memcpy(p[1],tp,sizeof(tp));
				for(int k=0;k<=N;k++)p[1][k]=tp[k];
				vector<R>vc;
				for(int k=0;(1<<k)<=j;k++)
				{
					if(j&(1<<k))vc.PB(r[i+k]);
				}
				if(SIZE(vc)!=num)continue;
				//printf("test %d\n",j);
				bool tf=true;
				for(int k=0;k<num&&tf;k++)
				{
					int x=find(vc[k].a,1);
					int y=find(vc[k].b,1);
					//printf("%d %d %d %d\n",vc[i]);
					if(x!=y)
					{
						U(x,y,1);
					}
					else tf=false;
				}
				if(tf)pp++;
			}
			ans*=(ll)pp;
			ans%=(ll)K;
			i+=n;
		}
		if(tmp==N-1)printf("%d\n",(int)ans);
		else puts("-1");
	}
	return 0;
}

