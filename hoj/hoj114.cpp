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
char s[500010];
ll L[500010],R[500010],TL[500010],TR[500010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]=='?')
			{
				scanf(__lld" "__lld,&TL[i],&TR[i]);
			}
		}
		if(len&1)
		{
			puts("IMBA");
			continue;
		}
		priority_queue<ll>pq;
		int p=0;
		ll ans=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='(')p++;
			else if(s[i]==')')p--;
			else if(s[i]=='?')
			{
				pq.push(TR[i]-TL[i]);
				p--;
				ans+=TR[i];
			}
			if(p<0&&!pq.empty())
			{
				p+=2;
				ans-=pq.top();
				pq.pop();
			}
			if(p<0)
			{
				p=-INF;
				break;
			}
		}
		if(p==0)printf(__lld"\n",ans);
		else printf("IMBA\n");
	}
	return 0;
}

