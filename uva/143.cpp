#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
struct point{ double x,y;};
const double eps = 1e-6;
double xmin,xmax,ymin,ymax;
bool dy(double x,double y)	{	return x > y + eps;}	// x > y 
bool xy(double x,double y)	{	return x < y - eps;}	// x < y 
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y 
bool dd(double x,double y) 	{	return fabs( x - y ) < eps;}  // x == y
double crossProduct(point a,point b,point c)//向量 ac 在 ab 的方向 
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
bool check( point p[],int n)
{
	for(int i=0; i<n; i++)
		if( !dd(p[i].x,0.0) || !dd(p[i].y,0.0) )
			return false;
	return true;
}
bool in_trangle(point pot,point p[],int n)
{
	double area = 0.0;
	for(int i=0; i<n; i++)
		area += fabs(crossProduct(pot,p[i],p[(i+1)%n]));
	if( dd(area,fabs(crossProduct(p[0],p[1],p[2]))) )
	{
		if( !dd(area,0.0) ) return true;
		if( dyd(pot.x,xmin) && xyd(pot.x,xmax) && dyd(pot.y,ymin) && xyd(pot.y,ymax) )
			return true;
	}
	return false;
}
int main()
{
	point p[5];
	while( ~scanf("%lf%lf",&p[0].x,&p[0].y ) )
	{
		for(int i=1; i<=2; i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		if( check(p,3) ) break;
		xmin = 200.0;xmax = 0.0;ymin = 200.0;ymax = 0.0;
		for(int i=0; i<3; i++)
		{
			xmin = min(xmin,p[i].x);
			xmax = max(xmax,p[i].x);
			ymin = min(ymin,p[i].y);
			ymax = max(ymax,p[i].y);
		}
		int ans = 0;
		for(int i=1; i<=99; i++)
			for(int k=1; k<=99; k++)
			{
				point pot; pot.x = i; pot.y = k;
				if( in_trangle(pot,p,3) )
					ans++;
			}
		printf("%4d\n",ans);
	}
return 0;
}

