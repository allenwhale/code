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
struct DNA
{
	char s[60];
	int n;
	int no;
	DNA()
	{
	}
	DNA(char _s[],int _n,int _no)
	{
		strcpy(s,_s);
		n=_n;
		no=_no;
	}
	bool operator < (const DNA& t)const
	{
		if(t.n==n)return t.no>no;
		return t.n>n;
	};
};
int main()
{
	int T;
	DNA S[110];
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		if(i)puts("");
		int N,M;
		scanf("%d %d",&N,&M);
		for(int j=0;j<M;j++)
		{
			char tmp[60];
			scanf("%s",tmp);
			//printf(" %s\n",tmp);
			int cnt=0;
			for(int k=1;k<N;k++)
			{
				for(int l=0;l<k;l++)
				{
					if(tmp[l]>tmp[k])cnt++;
				}
			}
			S[j]=DNA(tmp,cnt,j);
			//printf("%s %d %d\n",S[j].s,S[j].n,S[j].no);
		}
		sort(S,S+M);
		for(int j=0;j<M;j++)
		{
			printf("%s\n",S[j].s);
		}
	}
	return 0;
}

