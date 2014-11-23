#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b
typedef  long long ll;
ll N,a;
ll d[50][50];
ll f(int x,int y)
{
	if(d[x][y]>=0)return d[x][y];
	if(x>=y)
	{
		ll t=0,b=0;
		if(x==N)t=0;
		else
		{
			for(int k=x+1;k<=N;k++)t=max(t,f(k,1)+f(k,y));
		}
		if(y==0)b=0;
		else
		{
			for(int k=1;k<y;k++)b=max(b,f(x,k)+f(N,k));
		}
		return d[x][y]=t+b;
	}
	else
	{
		for(int k=x;k<y;k++)
		{
			d[x][y]=max(d[x][y],f(x,k)+f(k+1,y));
		}
		return d[x][y];
	}
}
int main()
{
	while(~scanf("%d %d",&N,&a))
	{
		for(int i=0;i<30;i++)
		{
			for(int j=0;j<30;j++)
			{
				d[i][j]=-1;
			}
		}
		d[N][1]=a;
		f(1,N);
		printf("%lld\n",d[1][N]);
	}
    return 0;
}
