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
#include <deque>
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
char s[200010];
int main()
{
	int N;
	scanf("%d",&N);
	scanf("%s",s);
	deque<char>dq;
	for(int i=0;i<N;i++)
	{
		char c=s[i];
		if(SIZE(dq)==0)
		{
			printf("L");
			dq.push_back(c);
		}
		else if(dq.back()==c)
		{
			printf("R");
			dq.pop_back();
		}
		else if(dq.front()==c)
		{
			printf("L");
			dq.pop_front();
		}
		else 
		{
			if(i==N-1)
			{
				printf("R");
				dq.push_back(c);
			}
			else
			{
				if(s[i+1]==dq.back())
				{
					printf("L");
					dq.push_front(c);
				}
				else
				{
					printf("R");
					dq.push_back(c);
				}
			}
		}
	}
	return 0;
}

