#include <stdio.h>
#include <string.h>
struct trea
{
	int t,v;
}s[1000];
int dp[1010],con[1010],pre[1010];
bool ck(int t,int x)
{
	for(int i=pre[t],j=con[t];j>0;j--,i=pre[t])
	{
		if(i==x)return false;
		t-=s[i].t;
	}
	return true;
}
int t,w;
int main()
{
	int num=0;
	while(~scanf("%d %d",&t,&w))
	{
		if(num++)printf("\n");
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int d,v;
			scanf("%d %d",&d,&v);
			s[i].t=3*w*d;
			s[i].v=v;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=t;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i-s[j].t<0)continue;
				if(ck(i-s[j].t,j)&&dp[i]<dp[i-s[j].t]+s[j].v)
				{
					pre[i]=j;
					con[i]=con[i-s[j].t]+1;
					dp[i]=dp[i-s[j].t]+s[j].v;
				}
			}
		}
		int tt=t;
		printf("%d\n",dp[t]);
		printf("%d\n",con[t]);
		for(int i=0,j=pre[tt];i<con[t];i++,j=pre[tt])
		{
			printf("%d %d\n",s[j].t/(3*w),s[j].v);
			tt-=s[j].t;
		}
	}
    return 0;
}
