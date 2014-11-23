#include <bits/stdc++.h>
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
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int x1=0,y1=0,x2=2*1e9,y2=2*1e9;
		for(int i=0;i<N;i++)
		{
			int x,xx,y,yy;
			scanf("%d %d %d %d",&x,&y,&xx,&yy);
			x1=max(x1,x),x2=min(x2,xx);
			y1=max(y1,y),y2=min(y2,yy);
		}
		//printf("%d %d %d %d\n",x1,y1,x2,y2);
		if(x1<x2&&y1<y2)printf(__lld"\n",(ll)(x2-x1)*(y2-y1));
		else puts("0");
	}
	return 0;
}

