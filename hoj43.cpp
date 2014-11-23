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
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int h[410],a[410],c[410];
struct R
{
	int h,a,c;
	bool operator < (const R &n)const
	{
		return a<n.a;
	}
}r[410];
bool ok[50010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d",&r[i].h,&r[i].a,&r[i].c);
	}
	sort(r,r+N);
	MS(ok,false);
	ok[0]=true;
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<r[i].c;k++)
		for(int j=r[i].a;j-r[i].h>=0;j--)
		{
			if(ok[j-r[i].h])
			{
				//printf("%d\n",j);
				ok[j]=true;
			}
		}
	}
	for(int j=50000;j>=0;j--)
	{
		if(ok[j])
		{
			printf("%d\n",j);
			break;
		}
	}
	return 0;
}

