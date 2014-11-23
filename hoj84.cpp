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
int W,H;
struct H
{
	int x,y;
	H(){}
}h[100010];
int sx[100010],sy[100010];//,sumx=0,sumy=0;
ll ssx[100010],ssy[100010];
int N;
int main()
{
	scanf("%d %d",&W,&H);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&h[i].x,&h[i].y);
	}
	for(int i=0;i<N;i++)
	{
		sx[i]=h[i].x;
		sy[i]=h[i].y;
	}
	sort(sx,sx+N);
	sort(sy,sy+N);
	ssx[0]=sx[0];
	ssy[0]=sy[0];
	for(int i=1;i<N;i++)
	{
		ssx[i]=ssx[i-1]+(ll)sx[i];
		ssy[i]=ssy[i-1]+(ll)sy[i];	
	}
	ll ans=(ll)INF*(ll)INF;
	int x=INF,y=INF;
	int mx,my;
	for(int i=0;i<N;i++)
	{
		ll tmp=0;
		mx=my=N/2;
		tmp=-(ll)abs(h[i].x-sx[mx])-(ll)abs(h[i].y-sy[my]);
		tmp+=2ll*((ll)sx[mx]*(mx+1)-(ssx[mx]));
		tmp+=2ll*(-(ll)sx[mx]*(N-mx-1)+(ssx[N-1]-ssx[mx]));
		tmp+=2ll*((ll)sy[my]*(my+1)-(ssy[my]));
		tmp+=2ll*(-(ll)sy[my]*(N-my-1)+(ssy[N-1]-ssy[my]));
		if(tmp<ans)
		{
			ans=tmp;
			x=sx[mx];
			y=sy[my];
		}
		else if(tmp==ans)
		{
			if(sx[mx]<x)
			{
				x=sx[mx];
				y=sy[my];
			}
			else if(sx[mx]==x&&sy[my]<y)
			{
				y=sy[my];
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		ll tmp=0;
		mx=N/2;
		my=N/2-1;
		tmp=-(ll)abs(h[i].x-sx[mx])-(ll)abs(h[i].y-sy[my]);
		tmp+=2ll*((ll)sx[mx]*(mx+1)-(ssx[mx]));
		tmp+=2ll*(-(ll)sx[mx]*(N-mx-1)+(ssx[N-1]-ssx[mx]));
		tmp+=2ll*((ll)sy[my]*(my+1)-(ssy[my]));
		tmp+=2ll*(-(ll)sy[my]*(N-my-1)+(ssy[N-1]-ssy[my]));
		if(tmp<ans)
		{
			ans=tmp;
			x=sx[mx];
			y=sy[my];
		}
		else if(tmp==ans)
		{
			if(sx[mx]<x)
			{
				x=sx[mx];
				y=sy[my];
			}
			else if(sx[mx]==x&&sy[my]<y)
			{
				y=sy[my];
			}
		}		
	}
	for(int i=0;i<N;i++)
	{
		ll tmp=0;
		mx=N/2-1;
		my=N/2;
		tmp=-(ll)abs(h[i].x-sx[mx])-(ll)abs(h[i].y-sy[my]);
		tmp+=2ll*((ll)sx[mx]*(mx+1)-(ssx[mx]));
		tmp+=2ll*(-(ll)sx[mx]*(N-mx-1)+(ssx[N-1]-ssx[mx]));
		tmp+=2ll*((ll)sy[my]*(my+1)-(ssy[my]));
		tmp+=2ll*(-(ll)sy[my]*(N-my-1)+(ssy[N-1]-ssy[my]));
		if(tmp<ans)
		{
			ans=tmp;
			x=sx[mx];
			y=sy[my];
		}
		else if(tmp==ans)
		{
			if(sx[mx]<x)
			{
				x=sx[mx];
				y=sy[my];
			}
			else if(sx[mx]==x&&sy[my]<y)
			{
				y=sy[my];
			}
		}		
	}
	for(int i=0;i<N;i++)
	{
		ll tmp=0;
		mx=N/2-1;
		my=N/2-1;
		tmp=-(ll)abs(h[i].x-sx[mx])-(ll)abs(h[i].y-sy[my]);
		tmp+=2ll*((ll)sx[mx]*(mx+1)-(ssx[mx]));
		tmp+=2ll*(-(ll)sx[mx]*(N-mx-1)+(ssx[N-1]-ssx[mx]));
		tmp+=2ll*((ll)sy[my]*(my+1)-(ssy[my]));
		tmp+=2ll*(-(ll)sy[my]*(N-my-1)+(ssy[N-1]-ssy[my]));
		if(tmp<ans)
		{
			ans=tmp;
			x=sx[mx];
			y=sy[my];
		}
		else if(tmp==ans)
		{
			if(sx[mx]<x)
			{
				x=sx[mx];
				y=sy[my];
			}
			else if(sx[mx]==x&&sy[my]<y)
			{
				y=sy[my];
			}
		}
	}
	printf(__lld"\n",ans);
	printf("%d %d\n",x,y);
	return 0;
}

