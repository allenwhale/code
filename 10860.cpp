#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
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
char s[10010];
char p[105][110];
int N,dp[10010];
int find(int x)
{
	//printf(" %d\n",x);
	if(x<0)return 0;
	int &tmp=dp[x];
	if(tmp!=-1)return tmp;
	tmp=INF;
	for(int i=0;i<N;i++)
	{
		int len=strlen(p[i]);
		bool tf=true;
		for(int j=len-1,k=x;tf&&j>=0;j--,k--)tf=(s[k]==p[i][j]);
		if(!tf)continue;
		tmp=min(tmp,find(x-len)+1);
	}
	//printf("%d %d\n",x,tmp);
	return tmp;
}
int main()
{
	int T,t=1;
	scanf("%d",&T);
	while(T--)
	{
		MS(p,0);
		scanf("%s",s);
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%s",p[i]);
		for(int i=0;i<N;i++)
		{
			int l=strlen(p[i]);
			strcpy(p[i+N],p[i]);
			reverse(p[i+N],p[i+N]+l);
		}
		N*=2;
		MS(dp,-1);
		printf("Set %d: ",t++);
		int ans=find(strlen(s)-1);
		if(ans>=INF)printf("Not possible.\n");
		else printf("%d.\n",ans);
	}
	return 0;
}

