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
#define dist(a,b) ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
#define pp 150.0
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
struct round
{
	double x,y,r;
	round(){}
}r[110];
const double pi=acos(-1.0);
const double delta=2.0/pp*pi;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%lf %lf %lf",&r[i].x,&r[i].y,&r[i].r);
		}
		double ans=0.0;
		for(int i=0;i<N;i++)
		{
			int cnt=0;
			int check[110];
			for(int j=0;j<N;j++)
			{
				if(i==j)continue;
				if(dist(r[i],r[j])<(r[i].r+r[j].r)*(r[i].r+r[j].r))
					check[cnt++]=j;
			}
			int tans=0;
			for(int j=0;j<pp;j++)
			{
				double theta=delta*j;
				double x=cos(theta)*r[i].r+r[i].x;
				double y=sin(theta)*r[i].r+r[i].y;
				bool tf=true;
				struct round tmp;
				tmp.x=x,tmp.y=y;
				for(int k=0;k<cnt&&tf;k++)
				{
					if(dist(tmp,r[check[k]])<r[check[k]].r*r[check[k]].r)
						tf=false; 
				} 
				if(tf)tans++;
			} 
			ans+=2*pi*r[i].r/pp*(double)tans;
		}
		double a=log10(ans),b;
		b=floor(a);
		a=a-b;
		printf("%.2lf %d\n",pow(10,a),(int)b);
	}
	return 0;
}

