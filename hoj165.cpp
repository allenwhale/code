#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
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
int main()
{
	char s[1000010];
	scanf("%s",s);
	int len=strlen(s);
	if(len<7)
	{
		int t;
		sscanf(s,"%d",&t);
		printf("%d\n",t%8);
	}
	else
	{
		char t[4];
		t[2]=s[len-1];
		t[1]=s[len-2];
		t[0]=s[len-3];
		t[3]=0;
		//puts(t);
		int tt;
		sscanf(t,"%d",&tt);
		printf("%d\n",tt%8);
	}
	return 0;
}

