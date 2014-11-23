#include <stdio.h>
typedef long long ll;
ll C[110][110];
ll com(int a,int b)
{
	if(C[a][b]!=-1)return C[a][b];
	if(a==0&&b==0)return 1;
	if(a<=0)return 0;
	if(b<=0)return 1;
	return C[a][b]=com(a-1,b)+com(a-1,b-1);
}
int main()
{
	for(int i=0;i<110;i++)
	{
		for(int j=0;j<110;j++)
		{
			C[i][j]=-1;
		}
	}
	int n,m;
	while(scanf("%d %d",&n,&m))
	{
		if(n==0&&m==0)break;
		int k;
		k=(n-m)>m?m:(n-m);
		printf("%d things taken %d at a time is %lld exactly.\n",n,m,com(n,k));
	}
    return 0;
}
