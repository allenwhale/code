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
int N,M;
vector<int>vc[50010];
int in[50010];
int main()
{
	scanf("%d %d",&N,&M);
	MS(in,0);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vc[a].PB(b);in[b]++;
	}
	queue<int>q;
	for(int i=1;i<=N;i++)
		if(in[i]==0)q.push(i);
	vector<int>ans;
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		ans.PB(tmp);
		foreach(it,vc[tmp])
		{
			in[*it]--;
			if(in[*it]==0)q.push(*it);
		}
	}
	if(SIZE(ans)!=N)puts("-1");
	else
	{
		foreach(it,ans)
		{
			printf("%d\n",*it);
		}
	}
	return 0;
}

