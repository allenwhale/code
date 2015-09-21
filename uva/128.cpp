#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
#define MOD 34943
using namespace std;
int main()
{
	char s[1030];
	while(gets(s)!=NULL&&strcmp(s,"#")!=0)
	{
		int len=strlen(s);
		//reverse(s,s+len);
		//puts(s);
		int mod=0;
		for(int i=0;i<len;i++)
		{
			mod*=256;
			mod+=s[i];
			mod%=MOD;
		}
		///printf("  %d\n",mod);
		mod*=256;
		mod%=MOD;
		mod*=256;
		mod%=MOD;
		mod=(MOD-mod)%MOD;
		printf("%02X %02X\n",mod/256,mod%256);
		
	}
	return 0;
}

