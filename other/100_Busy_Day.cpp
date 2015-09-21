#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct work
{
	ll c;
	ll num;
	bool operator <(const work &n)const
	{
		if(n.c<c)return true;
		else if(n.c==c)
		{
			if(n.num>num)return true;
			return false;
		}
		return false;
	}
}w[300010];
int main()
{	
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&w[j].c);
			w[j].num=(ll)j+1;
		}
		sort(w,w+n);
		ll allc=0;
		for(int j=0;j<n;j++)
		{
			printf("%lld%c",w[j].num,j==n-1?'\n':' ');
			allc+=(ll)(j+1)*w[j].c;
		}
		printf("%lld\n",allc);
	}

	return 0;
}

