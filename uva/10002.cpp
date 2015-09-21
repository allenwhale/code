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
using namespace std;
int N;
struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y)
	{
		x=_x,y=_y;
	}
	Point operator - (const Point& a)const
	{
		Point tmp=Point(x-a.x,y-a.y);
		return tmp;
	}
}p[10010];
inline double cross(Point a,Point b)
{
	return a.x*b.y-a.y*b.x;
}
inline double dist2(Point a)
{
	return (a.x*a.x+a.y*a.y);
}
bool cmp(Point a,Point b)
{
	double c=cross(a-p[0],b-p[0]);
	if(c>0)return true;
	if(fabs(c)<=1e-9&&dist2(a-p[0])<dist2(b-p[0]))return true;
	else return false;
}
vector<Point>vc;
void graham()
{
	vc.push_back(p[0]);
	vc.push_back(p[1]);
	for(int i=2;i<N;i++)
	{
		while(SIZE(vc)>=2&&cross(*(vc.end()-1)-*(vc.end()-2),p[i]-*(vc.end()-1))<=0)vc.pop_back();
		vc.push_back(p[i]);
	}
	vc.push_back(vc[0]);
}
int main()
{
	while(~scanf("%d",&N)&&N>=3)
	{
		int mny=INF,mnx=INF,mn=-1;
		for(int i=0;i<N;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(mny>y)
			{
				mny=y,mnx=x,mn=i;
			}
			else if(mny==y&&mnx>x)
			{
				mnx=x,mn=i;
			}
			p[i]=Point((double)x,(double)y);
		}
		swap(p[0],p[mn]);
		sort(p+1,p+N,cmp);
		vc.clear();
		graham();
		double AREA=0.0;
		double sumx=0.0,sumy=0.0;
		foreach(it,vc)
		{
			if(it==vc.end()-1)break;
			double area=cross((*it),(*(it+1)));
			//printf("%lf %lf %lf\n",(*it).x,(*it).y,area);
			sumx+=((*it).x+(*(it+1)).x)/3*area;
			sumy+=((*it).y+(*(it+1)).y)/3*area;
			AREA+=area;
		}
		double cx=sumx/AREA,cy=sumy/AREA;
		if(fabs(cx)<=1e-9)cx=0.0;
		if(fabs(cy)<=1e-9)cy=0.0;
		printf("%.3lf %.3lf\n",cx,cy);
	}
	return 0;
}

