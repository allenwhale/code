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
#include <set>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
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
int A[1010],B[1000100];
int main()
{
	int N;
	int t=1;
	while(~scanf("%d",&N)&&N)
	{
		for(int i=0;i<N;i++)
			scanf("%d",&A[i]);
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				B[cnt++]=(A[i]+A[j]);
			}
		}
		sort(B,B+cnt);
		int M;
		scanf("%d",&M);
		printf("Case %d:\n",t++);
		while(M--)
		{
			int tmp;
			scanf("%d",&tmp);
			int ans;
			int l=0,r=cnt-1;
			while(true)
			{
				if(r-l==1)
				{
					if(B[r]-tmp<tmp-B[l])ans=B[r];
					else ans=B[l];
					break;
				}
				int mid=(l+r)>>1;
				if(B[mid]==tmp)
				{
					ans=tmp;
					break;
				}
				else if(B[mid]<tmp)l=mid;
				else r=mid;
			}
			
			printf("Closest sum to %d is %d.\n",tmp,ans);
		}
	}
	return 0;
}

