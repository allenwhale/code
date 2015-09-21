#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXV 1000010
#define MAXN 1010
long long w[MAXN],v[MAXN],n[MAXN];
long long dp[MAXV],p[MAXV],q[MAXV];

int N,V;
void pack(int x)
{
	for(int i=0;i<v[x];i++)
	{
		//printf("d %d\n",i);
		//system("pause");
		long long *pf=p,*pb=p-1;
		long long *qf=q,*qb=q-1;
 		for(int j=i,k=0;j<=V;j+=v[x],k++)
		{
			//printf("j %d\n",j);
			if(pb==pf+n[x])
			{
				if(*qf==*pf)qf++;
				pf++;
			}
			long long tmp=dp[j]-(long long)k*w[x];
			*++pb=tmp;
			while(qb>=qf&&*qb<tmp)qb--;
			*++qb=tmp;
			dp[j]=*qf+(long long)k*w[x];
		}
		//system("pause");
	}
}
int main()
{
	scanf("%d %d",&N,&V);
	for(int i=0;i<N;i++)
	{
		scanf("%lld %lld %lld",&n[i],&w[i],&v[i]);
	}
	for(int i=0;i<N;i++)
	{
		//printf(" %d\n",i);
		//system("pause");
		pack(i);
	}
	printf("%lld\n",dp[V]);
	return 0;
}
