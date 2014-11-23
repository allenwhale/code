#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PPF(a) push_front(a)
#define PF() pop_front()
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int p[148940],pn=0;
int dp[2000010],dp2[2000010],dp3[2000010];
bool pr[2000010];
void prime()
{
	p[pn++]=2;
	for(int i=3;i<=2000000;i+=2)
	{
		bool tf=true;
		for(int j=0;j<pn&&tf&&p[j]*p[j]<=i;j++)
		{
			if(i%p[j]==0)tf=false;
		}
		if(tf)p[pn++]=i,pr[i]=true;
	}
	//printf("%d\n",pn);
}
int find(int x)
{
	int &tmp=dp[x];
	if(tmp!=-1)return tmp;
	for(int i=0;i<pn;i++)
	{
		if(x%p[i]==0)
		{
			if((x/p[i])%p[i]==0)tmp=find(x/p[i])*p[i];
			else tmp=find(x/p[i])*(p[i]-1);
			return tmp;
		}
	}
	return -1;
}
int depth(int x)
{
	if(x==1)return 0;
	int &tmp=dp2[x];
	if(tmp!=-1)return tmp;
	return tmp=depth(find(x))+1;	
}
int main()
{
	MS(dp,-1);MS(dp2,-1);
	prime();
	dp3[2]=1;
	dp2[2]=1;
	dp[2]=1;
	for(int i=3;i<=2000000;i++)
	{
		//if(i%1000==0)printf("%d\n",i);
		if(!pr[i])
		for(int j=0;j<pn;j++)
		{
			if(i%p[j]==0)
			{
				if((i/p[j])%p[j]==0)dp[i]=dp[i/p[j]]*p[j];
				else dp[i]=dp[i/p[j]]*(p[j]-1);
				break;
			}
		}
		else dp[i]=i-1;
		dp2[i]=dp2[dp[i]]+1;
		dp3[i]=dp3[i-1]+dp2[i];
	}
	//puts("sss");
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp3[b]-dp3[a-1]);
	}
	return 0;
}

