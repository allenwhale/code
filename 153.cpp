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
long long func(int n)
{
	if(n==0)return 1LL;
	long long res=1LL;
	for(int i=1;i<=n;i++)
	{
		res*=(long long)i;
	}
	return res;
}
int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}
int main()
{
	char s[100];
	int n[30];
	while(gets(s)!=NULL&&strcmp(s,"#")!=0)
	{
		MS(n,0);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			n[s[i]-'a']++;
		}
		long long ans=0LL;
		for(int i=0;i<len-1;i++)
		{
			for(int j=0;j<s[i]-'a';j++)
			{
				if(n[j]<=0)continue;
				n[j]--;
				long long tmp;
				int set[50]={};
				for(int k=2;k<len-i;k++)
				{
					set[k]=k;
				}
				for(int k=0;k<26;k++)
				{
					//tmp/=func(n[k]);
					for(int l=2;l<=n[k];l++)
					{
						int ttmp=l;
						for(int o=2;o<len-i;o++)
						{
							int g=gcd(ttmp,set[o]);
							ttmp/=g;
							set[o]/=g;
						}
					}
				}
				n[j]++;
				tmp=1LL;
				for(int o=2;o<len-i;o++)
					tmp*=set[o];
				ans+=tmp;
				//printf("%d "__lld"\n",i,tmp);
			}
			
			n[s[i]-'a']--;
		}
		printf("%10lld\n",ans+1LL);
	}
	return 0;
}

