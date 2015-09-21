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
using namespace std;
#include <complex>
typedef complex<int>Cd;
Cd p[800];
int N;
int cross(Cd a,Cd b)
{
	return (conj(a)*b).imag();
}
int main()
{
	scanf("%d%*c",&N);
	getchar();
	while(N--)
	{		
		char tmp[1000];
		int cnt=0;
		while(gets(tmp)!=NULL&&strcmp(tmp,"")!=0)
		{
			int a,b;
			sscanf(tmp,"%d %d",&a,&b);
			p[cnt]=Cd(a,b);cnt++;
		}
		int ans=0;
		for(int i=0;i<cnt;i++)
		{
			for(int j=i+1;j<cnt;j++)
			{
				int MX=2;
				for(int k=j+1;k<cnt;k++)
				{
					Cd v1=p[k]-p[i],v2=p[k]-p[j];
					if(cross(v1,v2)==0)MX++;
				}
				ans=max(ans,MX);
			}
		}
		printf("%d\n",ans);
		if(N)puts("");
	}
	return 0;
}

