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
int s[65011*3],ptr[65011];
int main()
{
	int N;
	scanf("%d",&N);
	int front,back;
	for(int i=0;i<N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		ptr[tmp]=i+65000;
		s[i+65000]=tmp;
	}
	front=65000;
	back=65000+N-1;
	while(true)
	{
		char c[2];int x;
		scanf("%s",c);
		if(c[0]=='A')
		{
			scanf("%d",&x);	
			s[ptr[x]]=0;
			ptr[x]=--front;
			s[front]=x;
		}
		else if(c[0]=='B')
		{
			scanf("%d",&x);
			s[ptr[x]]=0;
			ptr[x]=++back;
			s[back]=x;
		}
		else 
		{
			break;
		}
	}
	printf("%d",s[front]);
	for(int i=front+1;i<=back;i++)
		if(s[i]!=0)printf(" %d",s[i]);
	return 0;
}

