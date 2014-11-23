#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <time.h>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#ifndef _PUSH_POP_
#define _PUSH_POP_
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#endif
#ifndef _MS_
#define _MS_
#define MS(s,v) memset(s,v,sizeof(s))
#endif
#ifndef _PAIR_
#define _PAIR_
#define PI pair<int,int>
#define PD pair<double,double>
#define PL pair<long long,long long>
#define MP(a,b) make_pair(a,b)
#define FF first
#define SS second
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
vector<int>s[26];
int N,K;
char ch[1010],prz[110];
int dp[1010][110];
int main()
{
	
	scanf("%d %d%*c",&N,&K);
	gets(ch+1);
	gets(prz+1);
	for(int i=1;i<=N;i++)
	{
		s[ch[i]-'a'].PB(i);
	}
	for(int i=0;i<s[prz[1]-'a'].size();i++)
	{
		dp[s[prz[1]-'a'][i]][1]=1;
	}
	for(int i=2;i<=K;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[j][i]=0;
			if(prz[i]==ch[j])
			{
				int ptr=prz[i-1]-'a';
				int sz=s[ptr].size();
				for(int k=0;k<sz;k++)
				{
					if(s[ptr][k]>=j)break;
					dp[j][i]+=dp[s[ptr][k]][i-1];
				}
			}
			
		}
	}
	int ans=0;
	for(int i=0;i<s[prz[K]-'a'].size();i++)
	{
		ans+=dp[s[prz[K]-'a'][i]][K];
	}
	printf("%d\n",ans);
 	return 0;
}

