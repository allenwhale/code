#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
#define VAR(a,b)        __typeof(b) a=(b)
//#define FORE(a,b)       for(VAR(a,(b).begin());a!=(b).end();++a)
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
using namespace std;
int main()
{
	vector<int>vc(100,10);
	
	foreach(it,vc)
	{
		printf("%d\n",(*it));
	}
	
	for(vector<int>::iterator it=vc.begin();it!=vc.end();it++)
	{
		printf("%d\n",(*it));
	}
	return 0;
}

