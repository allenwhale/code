#include <stdio.h>
#include <string.h>
#define MAXN 5000010
bool flag[MAXN];
bool isprime[MAXN];
int sum[MAXN];
int p[348520],pn=0;
void init()
{
	p[pn++]=2;
	for(int i=3;i<MAXN;i+=2)
	{
		bool tf=true;
		for(int j=0;j<pn&&p[j]*p[j]<=i;j++)
		{
			if(i%p[j]==0)
			{
				tf=false;
				break;
			}
		}
		if(tf)p[pn++]=i;
	}
	//printf("%d\n",pn);
	flag[0]=flag[1]=false;flag[2]=true;
	sum[1]=0;sum[2]=2;
	for(int i=0;i<pn;i++)isprime[p[i]]=true;
	for(int i=3;i<MAXN;i++)
	{
		if(isprime[i])flag[i]=true,sum[i]=i;
		else
		{
			for(int j=0;j<pn;j++)
			{
				if(i%p[j]==0)
				{
					if(i/p[j]%p[j]!=0)sum[i]=sum[i/p[j]]+p[j];
					else sum[i]=sum[i/p[j]];
					break;
				}
			}
			if(isprime[sum[i]])flag[i]=true;
			else flag[i]=false;
		}
	}
}
int main()
{
	init();
	int a,b;
	while(~scanf("%d %d",&a,&b)&&a&&b)
	{
		int cnt=0;
		for(int i=a;i<=b;i++)
		{
			if(flag[i])cnt++;
		}
		printf("%d\n",cnt);
	}
}
