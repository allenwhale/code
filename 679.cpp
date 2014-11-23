#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int main()
{
	int D,I;
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d",&D,&I);
		int a=I-1;
		int aa=0;
		for(int i=0;i<(D-1);i++)
		{
			//i,D-1-i
			int b=(a>>i)&1;//,c=a&(1<<(D-i-1));
			aa+=(b<<(D-1-i));
			//aa+=(c<<i);
		}
		printf("%d\n",(1<<(D-1))+aa/2);
	}
	return 0;
}

