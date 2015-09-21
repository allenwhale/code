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
int z[110];
int dp[110][110];
char s[100];
int Z_func(char *a,char *b)
{
	int len=(int)(b-a)+1;
	z[0]=len;
	int L=0,R=1;
	for(int i=1;i<len;i++)
	{
		if(R<=i||z[i-L]>=R-i)
		{
			int x=R<=i?i:R;
			while(x<len&&a[x]==a[x-i])x++;
			z[i]=x-i;
			if(i<x)L=i,R=x;
		}
		else z[i]=z[i-L];
	}
	int ans=-1;
	for(int i=1;i<len;i++)
	{
		//printf(" %d %d\n",i,z[i]);
		if(z[i]+i==len&&len%i==0)
		{
			ans=i;break;
		}
	}
	if(ans==-1)return len;
	else return ans;
}
int dfs(int l,int r)
{
	int &tmp=dp[l][r];
	if(tmp!=-1)return tmp;
	if(l==r)return tmp=1;
	tmp=Z_func(s+l,s+r);
	if(tmp!=r-l+1)
	{
		tmp=min(tmp,dfs(l,l+tmp-1));
	}
	//printf("%d %d %d\n",l,r,tmp);
	for(int i=l;i<r;i++)
	{
		tmp=min(tmp,dfs(l,i)+dfs(i+1,r));
	}
	
	return tmp;
}
int main()
{
	
	while(~scanf("%s",s)&&strcmp(s,"*")!=0)
	{
		//printf("%d\n",Z_func(s+1,s+2));
		MS(dp,-1);
		int len=strlen(s);
		int ans=dfs(0,len-1);
		printf("%d\n",ans);
	}
	return 0;
}

