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
double p[10];
double dp[100][20];
int main()
{
	int N;
	int t=1;
	while(~scanf("%d",&N)&&N)
	{
		for(int i=0;i<N;i++)
		{
			int idx;
			double pp;
			scanf("%d %lf",&idx,&pp);
			p[idx]=pp;
		}
		int Q;
		scanf("%d",&Q);
		printf("Case %d:\n",t++);
		while(Q--)
		{
			char s[100];
			scanf("%s",s+1);
			int len=strlen(s+1);
			for(int i=0;i<=len;i++)
			{
				for(int j=0;j<11;j++)
					dp[i][j]=0.0;
			}
			dp[0][0]=1.0;
			for(int i=1;i<=len;i++)
			{
				for(int j=0;j<11;j++)
				{
					if(s[i]=='*')
					{
						for(int k=0;k<10;k++)
							dp[i][(j*10+k)%11]+=dp[i-1][j]*p[k];
					}
					else
					{
						int tmp=s[i]-'0';
						dp[i][(j*10+tmp)%11]=dp[i-1][j];
					}
				}
			}
			int R;
			scanf("%d",&R);
			printf("%.8lf\n",dp[len][R]);
		}
	}
	return 0;
	
}

