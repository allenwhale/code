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
char s1[70],s2[70],s3[70];
int dp[70][70][70];
int sum11[70][70],sum22[70][70];
int main()
{
	int T;
	scanf("%d",&T);
	int l1,l2,l3,i,j,k;
	while(T--)
	{
		scanf("%s %s %s",s1+1,s2+1,s3+1);
		l1=strlen(s1+1),l2=strlen(s2+1),l3=strlen(s3+1);		
		//MS(dp,0);
		for(j=0;j<=l1+1;j++)
		{
			for(k=0;k<=l2+1;k++)
			{
				dp[0][j][k]=1;
			}
		}
		for(i=1;i<=l3;i++)
		{
			//MS(sum11,0);
			//MS(sum22,0);
			for(j=0;j<=l1+1;j++)
			{
				for(k=1;k<=l2+1;k++)
				{
					sum11[j][k]=sum11[j][k-1]+(s2[k]==s3[i]?dp[i-1][j][k]:0);
					if(sum11[j][k]>=10007)sum11[j][k]%=10007;
				}
			}
			for(k=0;k<=l2+1;k++)
			{
				for(j=1;j<=l1+1;j++)
				{
					sum22[j][k]=sum22[j-1][k]+(s1[j]==s3[i]?dp[i-1][j][k]:0);
					if(sum22[j][k]>=10007)sum22[j][k]%=10007;
				}
			}
			for(j=1;j<=l1+1;j++)
			{
				for(k=1;k<=l2+1;k++)
				{
					dp[i][j][k]=sum11[j][k-1]+sum22[j-1][k];
					if(dp[i][j][k]>=10007)dp[i][j][k]%=10007;
				}
			}
		}
		printf("%d\n",dp[l3][l1+1][l2+1]);
		
	}
	return 0;
}
