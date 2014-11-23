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
#ifdef __AintEN
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
char tmp[22001000],s[22000010];
int z[22001000];
int N;
int match(int a,int b)
{
	int i=0;
	while(a-i>=0&&b+i<N&&s[a-i]==s[b+i])i++;
	return i;
}
int main()
{
	gets(tmp);
	MS(s,'.');
	N=strlen(tmp);
	for(int i=0;i<N;i++)
	{
		s[i*2+1]=tmp[i];
	}
	N=N*2+1;
	int L=0,R=0;
	z[0]=1;
	for(int i=1;i<N;i++)
	{
		int ii=L-(i-L);
		int n=R-i+1;
		if(i>R)
		{
			z[i]=match(i,i);
			L=i;R=i+z[i]-1;
		}
		else if(z[ii]==n)
		{
			z[i]=n+match(i-n,i+n);
			L=i;R=i+z[i]-1;
		}
		else z[i]=min(z[ii],n);
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		ans=max(ans,((z[i]*2-1)/2));
	}
	printf("%d\n",ans);
	return 0;
}

