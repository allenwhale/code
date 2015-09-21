#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
#define maxn(a,b) (a>b?a:b)
using namespace std;
deque<int>dq[100];
int dp[100];
int pre[100];
int n;
int N;
struct Cube
{
	int w1,w2,h;
}s[100];
Cube cube(int t1,int t2,int h)
{
	Cube work;
	work.w1=t1;
	work.w2=t2;
	work.h=h;
	return work;
}
bool ck(int up,int dn)
{
	int u1,u2,d1,d2;
	u1=s[up].w1;
	u2=s[up].w2;
	d1=s[dn].w1;
	d2=s[dn].w2;
	return ((u1<d1&&u2<d2)||(u1<d2&&u2<d1));
}
void build()
{
	for(int i=0;i<3*N;i++)
	{
		for(int j=0;j<3*N;j++)
		{
			if(ck(j,i))
			{
				//printf("%d %d\n",i,j);
				dq[i].push_back(j);
			}
		}
	}
}
int find(int x)
{
	//printf(" %d\n",x);
	if(dp[x]!=-1)return dp[x];
	int tmp=0;
	int size=dq[x].size();
	for(int i=0;i<size;i++)
	{
		tmp=max(tmp,find(dq[x][i]));
		//printf("%d %d\n",x,tmp);
	}
	return (dp[x]=tmp+s[x].h);
}
int main()
{
	int num=1;
	while(scanf("%d",&N))
	{
		if(N==0)break;
		n=0;
		memset(s,0,sizeof(s));
		//memset(dp,0,sizeof(dp));
		for(int i=0;i<N*3;i++)
		{
			dp[i]=-1;
			dq[i].clear();
		}
		for(int i=0;i<N;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			s[i*3]=cube(a,b,c);
			s[i*3+1]=cube(a,c,b);
			s[i*3+2]=cube(b,c,a);
		}
		int ans=0;
		build();
		//printf("f");
		for(int i=0;i<3*N;i++)
		{
			//printf("%d\n",find(i));
			ans=max(ans,find(i));
		}
		printf("Case %d: maximum height = %d\n",num++,ans);
	}
    return 0;
}
