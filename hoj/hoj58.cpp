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
#define lb(i) (i&(-i))
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int bit[1030][1030];
int N;
void add(int x,int y,int num)
{
	for(int i=x;i<=N;i+=lb(i))
	{
		for(int j=y;j<=N;j+=lb(j))
		{
			bit[i][j]+=num;
		}
	} 
}
int sum(int x,int y)
{
	int res=0;
	for(int i=x;i;i-=lb(i))
	{
		for(int j=y;j;j-=lb(j))
		{
			res+=bit[i][j];
		}
	}
	return res;
}
int main()
{
	scanf("%d",&N);
	int cmd;
	while(~scanf("%d",&cmd))
	{
		if(cmd==1)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);	
			x++,y++;
			add(x,y,z);
		
		}
		else if(cmd==2)
		{
			int x1,x2,y1,y2;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++,x2++,y1++,y2++;
			int mnx=min(x1,x2),mxx=max(x1,x2),mny=min(y1,y2),mxy=max(y1,y2);
			//printf("%d %d %d %d\n",sum(mxx,mxy),sum(mxx,mny-1),sum(mnx-1,mxy),sum(mnx-1,mny-1));
			printf("%d\n",sum(mxx,mxy)-sum(mxx,mny-1)-sum(mnx-1,mxy)+sum(mnx-1,mny-1));
		}
	}
	return 0;
}

