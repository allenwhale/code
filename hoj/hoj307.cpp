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
int l[70010];
bool vis[70010];
bool find(int x)
{
	MS(vis,false);
	while(true)
	{
		//printf("%d\n",x);
		if(x==1)return true;
		if(vis[x])break;
		vis[x]=true;
		char tmp[100];
		sprintf(tmp,"%d",x);
		int n=0;
		for(int i=0;tmp[i];i++)
			n+=(tmp[i]-'0')*(tmp[i]-'0');
		x=n;
	}
	return false;
}
int main()
{
	/*
	int cnt=1;
	for(int i=2;i<=70000;i++)
	{
		if(find(i))
		{
			cnt++;
			if(cnt==10)printf("%d\n",i);
			else if(cnt==50)printf("%d\n",i);
			else if(cnt==100)printf("%d\n",i);
			else if(cnt==1000)printf("%d\n",i);
			else if(cnt==10000)printf("%d\n",i);
		}
	}*/
	printf("44\n320\n694\n6899\n67169\n");
	return 0;
}

