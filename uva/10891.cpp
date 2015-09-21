#include <stdio.h>
#include <string.h>
#define MAXN 110
#define SUM(a,b) (sum[(b)]-sum[(a)-1])
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int N,s[MAXN],sum[MAXN];
int dp[MAXN][MAXN];
int fdp[MAXN][MAXN];
int gdp[MAXN][MAXN];
int find(int l,int r);
int ffind(int l,int r);
int gfind(int l,int r);
int main()
{
	while(~scanf("%d",&N)&&N)
	{
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&s[i]);
			sum[i]=sum[i-1]+s[i];
		}
		memset(dp,0x3f,sizeof(dp));
		memset(fdp,0x3f,sizeof(fdp));
		memset(gdp,0x3f,sizeof(gdp));
		printf("%d\n",-SUM(1,N)+2*find(1,N));
	}
	return 0;
}
int ffind(int l,int r)
{
	int &tmp=fdp[l][r];
	if(tmp!=0x3f3f3f3f)return tmp;
	if(l>r)return tmp;
	//tmp=-tmp;
	//tmp=0;
	return tmp=min(ffind(l+1,r),find(l,r));
}
int gfind(int l,int r)
{
	int &tmp=gdp[l][r];
	if(tmp!=0x3f3f3f3f)return tmp;
	if(l>r)return tmp;
	//tmp=0;
	return tmp=min(gfind(l,r-1),find(l,r));
}
int find(int l,int r)
{
	int &tmp=dp[l][r];
	if(tmp!=0x3f3f3f3f)return tmp;
	if(l==r)return tmp=s[l];
	//if(l>r)return tmp=0;
	int sub=SUM(l,r);
	tmp=0;
	tmp=sub-min(min(ffind(l+1,r),gfind(l,r-1)),tmp);
	//printf(" %d %d %d\n",l,r,tmp);
	return tmp;
}