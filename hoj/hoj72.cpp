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
#define PF(a) push_front(a)
#define PPF() pop_front()
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
struct MAT
{
	ll d[4][4];
	MAT(){}
	MAT(ll l[])
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				d[i][j]=l[i*4+j];
			}
		}
	}
};
MAT mul(MAT a,MAT b)
{
	ll tmp[20]={0};
	MAT c=MAT(tmp);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				c.d[i][j]+=a.d[i][k]*b.d[k][j];
			}
		}
	}
	return c;
}
MAT POW(MAT a,int n)
{
	ll tmp[]={
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1};
	MAT c=MAT(tmp);
	while(n)
	{
		if(n&1)c=mul(c,a);
		a=mul(a,a);
		n>>=1;
	}
	return c;
}
int main()
{
	int n1,n2,n3,d,n;
	while(~scanf("%d %d %d %d %d",&n1,&n2,&n3,&d,&n))
	{
		ll tmp[]={
			0,0,1,0,
			1,1,-1,1,
			0,1,0,0,
			0,0,0,1};
		MAT s=MAT(tmp);
		n--;
		s=POW(s,n);

		printf(__lld"\n",s.d[0][0]*n1+s.d[0][1]*n3+s.d[0][2]*n2+s.d[0][3]*d);
	}
	return 0;
}

