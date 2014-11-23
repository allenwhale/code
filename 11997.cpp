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
int L1[800],L2[800];
int main()
{
	int K;
	while(~scanf("%d",&K))
	{
		for(int i=0;i<K;i++)
		{
			scanf("%d",&L1[i]);
		}
		sort(L1,L1+K);
		for(int i=0;i<K-1;i++)
		{
			for(int j=0;j<K;j++)
			{
				scanf("%d",&L2[j]);
			}
			sort(L2,L2+K);
			priority_queue<pI,vector<pI>,greater<pI> >pq;
			for(int j=0;j<K;j++)
			{
				pq.push(MP(L1[j]+L2[0],0));
			}
			for(int j=0;j<K;j++)
			{
				pI tmp=pq.top();
				pq.pop();
				L1[j]=tmp.FF;
				if(tmp.SS+1<K)
				{
					pq.push(MP(tmp.FF-L2[tmp.SS]+L2[tmp.SS+1],tmp.SS+1));
					
				}
			}
		}
		for(int i=0;i<K-1;i++)
		{
			printf("%d ",L1[i]);
		}
		printf("%d\n",L1[K-1]);
	}
	
	return 0;
}

