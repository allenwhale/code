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
int n[100010],m[100010];
int main()
{
	int N,M,S;
	scanf("%d %d %d",&N,&M,&S);
	for(int i=0;i<N;i++)
		scanf("%d",&n[i]);
	for(int i=0;i<M;i++)
		scanf("%d",&m[i]);
	sort(n,n+N);
	sort(m,m+M);
	ll ans=0;
	for(int i=0;i<N;i++)
	{
		if(n[i]>S)break;
		ans+=(ll)(upper_bound(m,m+M,S-n[i])-m);
	}
	printf(__lld"\n",ans);
	return 0;
}

