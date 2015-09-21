#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <complex>
#include <math.h>
using namespace std;
typedef double db;
typedef complex<db> cd;
struct node
{
	cd nn;
	int num;
	db angle;
}n[1000];
bool cmp(node a,node b)
{
	if(a.angle!=b.angle)return a.angle<b.angle;
	else return a.nn.real()<b.nn.real();
}
db len[1000];
int main()
{
	db x,y;
	db mny=1e9;
	int mnyindex;
	int N=0;
	while(~scanf("%lf %lf",&x,&y))
	{
		if(mny>y)
		{
			mny=y;
			mnyindex=N;
		}
		n[N++].nn=cd (x,y);
	}
	for(int i=0;i<N;i++)
	{
		if(i==mnyindex)continue;
		n[i].nn-=n[mnyindex].nn;
		n[i].angle=arg(n[i].nn);
	}
	n[mnyindex].nn=cd (0,0);
	sort(n,n+N,cmp);
	//db ans=0.0;
	for(int i=0;i<N-1;i++)
	{
		//cout<<n[i].nn<<n[i+1].nn<<endl;
		len[i]=abs(n[i].nn-n[i+1].nn);
	}
	len[N-1]=abs(n[0].nn-n[N-1].nn);
	sort(len,len+N);
	for(int i=0;i<N;i++)
	{
		printf("%lf\n",len[i]);
	}
	//printf("%lf\n",ans);
	return 0;
}

