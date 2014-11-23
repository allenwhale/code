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
#include <map>
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
int main()
{
	int T;
	scanf("%d%*c",&T);
	getchar();
	while(T--)
	{
		map<string,int>mp;
		char s[100];
		int cnt=0;
		while(gets(s)!=NULL&&s[0])
		{
			cnt++;
			if(mp.count(s)==0)mp[s]=1;
			else mp[s]++;
		}
		foreach(it,mp)
		{
			cout<<it->FF;
			printf(" %.4lf\n",(double)it->SS*100.0/cnt);
		}
		if(T)puts("");
	}
	return 0;
}

