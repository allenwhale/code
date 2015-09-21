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
#define dist(a,b) (sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y)))
using namespace std;
struct P
{
	double x,y;
}p[3];
int main()
{
	while(~scanf("%lf %lf %lf %lf %lf %lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y))
	{
		double a,b,c;
		a=dist(0,1);
		b=dist(1,2);
		c=dist(0,2);
		double sinarg=sin(acos((a*a+b*b-c*c)/(2.0*a*b)));
		double r=c/sinarg/2.0;
		printf("%.2lf\n",2*r*acos(-1));
	}
	return 0;
}

