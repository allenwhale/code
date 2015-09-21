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
bool mp[3050][3050],is[3050];
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	MS(mp,false);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		mp[a][b]=mp[b][a]=true;
		is[a]=is[b]=true;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if(!mp[i][j]&&is[i]&&is[j])
			{
				is[i]=is[j]=false;
			}
		}
	}
	vector<int>vc;
	vc.clear();
	for(int i=1,j=0;j<N/3&&i<=N;i++)
	{
		if(is[i])
		{
			vc.PB(i);
			j++;
		}
	}
	foreach(it,vc)
	{
		printf("%d%c",*it,it==vc.end()-1?'\n':' ');
	}
	return 0;
}

