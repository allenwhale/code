/*
ID: allenwh1
PROG: holstein
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define ms(a) memset(a,0,sizeof(a))
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
int V;
int v[30];
int G;
int g[20][30];
int work[30];
int minnum=1e9;
int lownum=1e9;
int main()
{
	fin("holstein.in");
	fout("holstein.out");
	scanf("%d",&V);
	for(int i=1;i<=V;i++)scanf("%d",&v[i]);
	scanf("%d",&G);
	for(int i=1;i<=G;i++)
	{
		for(int j=1;j<=V;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	for(int i=1;i<1<<G;i++)
	{
		ms(work);
		int n=0,now=0,nlow=i,tmp;
		tmp=i;
		while(tmp>0)
		{
			now++;
			if(tmp&1)n++;
			tmp>>=1;
		}
		tmp=i;
		now=0;
		while(tmp>0)
		{
			now++;
			if(tmp&1)
			{
				for(int j=1;j<=V;j++)
				{
					work[j]+=g[now][j];
				}
			}
			tmp>>=1;
		}
		bool tf=true;
		for(int j=1;j<=V&&tf;j++)
		{
			if(work[j]<v[j])tf=false;
		}
		if(tf)
		{
			if(n>minnum)continue;
			else if(n==minnum&&nlow<lownum)
			{
				lownum=nlow;
			}
			else 
			{
				minnum=n;
				lownum=nlow;
			}
		}
	}
	printf("%d",minnum);
	int now=0,n=0;
	while(lownum>0)
	{
		now++;
		if(lownum&1)printf(" %d",now);
		lownum>>=1;
	}
	printf("\n");
	//while(1);
    return 0;
}
