#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int p[3800];
int pn=0;
void makeprime()
{
	p[pn++]=2,p[pn++]=3;
	for(int i=5;i<=35000;i+=2)
	{
		bool tf=true;
		for(int j=0;j<pn&&p[j]*p[j]<=i&&tf;j++)
		{
			if(i%p[j]==0)tf=false;
		}
		if(tf)p[pn++]=i;
	}
}
int count(int x)
{
	int ans=1;
	for(int i=0;p[i]<=x&&i<pn;i++)
	{
		int cnt=1;
		while(x%p[i]==0)
		{
			//printf("%d\n",p[i]);
			cnt++;
			x/=p[i];
		}
		ans*=cnt;
	}
	return ans;
}
int main()
{
	makeprime();
	//count(6);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int mx=-1,mn=INF;
		for(int i=l;i<=r;i++)
		{
			int tmp=count(i);
			//printf("%d %d\n",i,tmp);
			if(mx<tmp)
			{
				mn=i,mx=tmp;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,r,mn,mx);
	}
	return 0;
}

