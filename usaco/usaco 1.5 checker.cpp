/*
ID: allenwh1
PROG: checker
LANG: C++ 
*/
#include <stdio.h>
#include <string.h>
#define fo freopen
int N;
int num=0;
bool h[100],x[100],y[100];
int ans[20];
void pr()
{
	printf("%d",ans[0]);
	for(int i=1;i<N;i++)
	{
		printf(" %d",ans[i]);
	}
	printf("\n");
}
void DFS(int n)
{
	if(n==N+1)
	{
		if(num++<3)pr();
		return;
	}
	for(int i=1;i<=N;i++)
	{
		if(h[i]&&x[i-n+N]&&y[i+n])
		{
			h[i]=x[i-n+N]=y[i+n]=false;
			ans[n-1]=i;
			DFS(n+1);
			h[i]=x[i-n+N]=y[i+n]=true;
		}
	}
}
int main()
{
	fo("checker.in","r",stdin);
	fo("checker.out","w",stdout);
	memset(h,true,sizeof(h));
	memset(x,true,sizeof(x));
	memset(y,true,sizeof(y));
	scanf("%d",&N);
	DFS(1);
	printf("%d\n",num);
    return 0;
}
