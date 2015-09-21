#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
#include <complex>
#define MAXN 9
using namespace std;
typedef complex<double> Cd;
double tsp[MAXN][1<<MAXN];
int rev[MAXN][1<<MAXN];
double dist[MAXN][MAXN]; 
int N;
Cd p[MAXN];
double find(int x,int s)
{
	double &tmp=tsp[x][s];
	if(tmp>=1e-6)return tmp;
	if(s==0)return tmp=0.0;
	double mmin=1e15;
	for(int i=0;i<MAXN;i++)
	{
		if(i!=x&&s&(1<<i))
		{
			double ttmp=dist[x][i]+find(i,s^(1<<i));
			if(ttmp<mmin)
			{
				mmin=ttmp;
				rev[x][s]=i;
			}
			mmin=min(mmin,ttmp);
		}
	}
	return mmin;
}
void init()
{
	for(int i=0;i<MAXN;i++)
	{
		for(int j=0;j<(1<<MAXN);j++)
		{
			tsp[i][j]=-1.0;
		}
	}
}
int main()
{
	int T=1;
	while(~scanf("%d",&N)&&N)
	{
		init();
		for(int i=0;i<N;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			p[i]=Cd(a,b);
		}
		for(int i=0;i<N;i++)
		{
			for(int j=i;j<N;j++)
			{
				dist[i][j]=dist[j][i]=abs(p[i]-p[j])+16.0;
			}
		}
		double mn=1e15;
		int st=-1;
		for(int i=0;i<N;i++)
		{
			double tmp=find(i,((1<<N)-1)^(1<<i));
			if(tmp<mn)
			{
				mn=tmp;st=i;
			}
		}
		puts("**********************************************************");
		printf("Network #%d\n",T++);
		for(int x=st,s=((1<<N)-1)^(1<<st);s;x=rev[x][s],s^=(1<<x))
		{
			printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",
					p[x].real(),p[x].imag(),p[rev[x][s]].real(),p[rev[x][s]].imag(),dist[x][rev[x][s]]);
		}
		printf("Number of feet of cable required is %.2lf.\n",mn);
	}
	return 0;
}

