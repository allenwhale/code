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
int p[10000],pn=0;
bool prime[65010];
void Prime()
{
	p[pn++]=2;
	for(int i=3;i<=65000;i+=2)
	{
		bool tf=true;
		for(int j=0;j<pn&&p[j]*p[j]<=i&&tf;j++)
			if(i%p[j]==0)tf=false;
		if(tf)p[pn++]=i;
	}
	MS(prime,false);
	for(int i=0;i<pn;i++)
		prime[p[i]]=true;
}
int mod(int a,int n)
{
	long long ans=1;
	long long tmp=a;
	int y=n;
	while(y)
	{
		if(y&1)
		{
			ans*=tmp;
			ans%=n;
		}
		tmp*=tmp;
		tmp%=n;
		y>>=1;
	}
	return ans;
}
bool check(int n)
{
	for(int i=2;i<n;i++)
	{
		if(mod(i,n)!=i)return false;
	}
	return true;
}
int main()
{
	Prime();
	int N;
	while(~scanf("%d",&N)&&N)
	{
		if(!prime[N]&&check(N))printf("The number %d is a Carmichael number.\n",N);
		else printf("%d is normal.\n",N);
	}
	return 0;
}

