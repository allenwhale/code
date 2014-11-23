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
queue<int>q;
int d[1000010];
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	MS(d,0x3f);
	d[a]=0;
	q.push(a);
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		if(tmp+1<=1000000&&d[tmp+1]>d[tmp]+2)
		{
			d[tmp+1]=d[tmp]+2;
			q.push(tmp+1);
		}
		if(tmp+2<=1000000&&d[tmp+2]>d[tmp]+3)
		{
			d[tmp+2]=d[tmp]+3;
			q.push(tmp+2);
		}
		if(tmp-1>=0&&d[tmp-1]>d[tmp]+2)
		{
			d[tmp-1]=d[tmp]+2;
			q.push(tmp-1);
		}
		if(tmp-2>=0&&d[tmp-2]>d[tmp]+3)
		{
			d[tmp-2]=d[tmp]+3;
			q.push(tmp-2);
		}
		if(tmp*2<=1000000&&d[tmp*2]>d[tmp]+3)
		{
			d[tmp*2]=d[tmp]+3;
			q.push(tmp*2);
		}
		if(tmp/2>=0&&d[tmp/2]>d[tmp]+3)
		{
			d[tmp/2]=d[tmp]+3;
			q.push(tmp/2);
		}
	}
	printf("%d\n",d[b]);
	return 0;
}

