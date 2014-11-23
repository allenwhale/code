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
using namespace std;
typedef complex<double> Cd;
Cd p[5];
double cross(Cd a,Cd b)
{
	return (conj(a)*b).imag();
}
int main()
{
	int N;
	scanf("%d",&N);
	puts("INTERSECTING LINES OUTPUT");
	while(N--)
	{		
		for(int i=0;i<4;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			p[i]=Cd(a,b);
		}
		/*
		
		*/
		Cd d1=p[0]-p[1],d2=p[2]-p[3];
		//printf("%lf\n",cross(d1,d2));
		if(fabs(cross(d1,d2))<=1e-6)
		{
			Cd t1=p[2]-p[0],t2=p[3]-p[0];
			//printf("%lf\n",cross(t1,t2));
			if(fabs(cross(t1,t2))<=1e-6)
			{
				puts("LINE");
			}
			else
			{
				puts("NONE");
			}
		}
		else
		{
			double c1,c2;
			c1=fabs(cross(p[2]-p[0],p[3]-p[0]));
			c2=fabs(cross(p[2]-p[1],p[3]-p[1]));
			Cd node=(p[0]*c2+p[1]*c1)/(c1+c2);
			printf("POINT %.2lf %.2lf\n",node.real(),node.imag());
		}
	}
	puts("END OF OUTPUT");
	return 0;
}

