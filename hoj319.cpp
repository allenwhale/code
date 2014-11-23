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
int main()
{
	int i;
	char s[20]="";
	scanf("%s",s);
	int a=1,b=1,flag=1;
	for(i=0;s[i];i++)
	{
		if(s[i]=='4')a=a*2;
		else if(s[i]=='7')a=a*2+1;
		else
		{
			if(s[i]<'4')a*=2;
			else if(s[i]<'7')a=a*2+1;
			else a++,a*=2;
			break;
		}
	}
	for(int j=i+1;s[j];j++)
		a<<=1;
		
	MS(s,0);
	scanf("%s",s);
	for(i=0;s[i];i++)
	{
		if(s[i]=='4')b=b*2;
		else if(s[i]=='7')b=b*2+1;
		else
		{
			if(s[i]<'4')b*=2;
			else if(s[i]<'7')b=b*2+1;
			else b++,b*=2;
			flag=0;
			break;
		}
	}
	for(int j=i+1;s[j];j++)
		b<<=1;
	printf("%d\n",b-a+flag);
	return 0;
}

