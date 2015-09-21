/*
ID: allenwh1
PROG: runround
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
typedef long long ll;
map<ll,ll>mp;
ll N;
bool ck(ll x)
{
	mp.clear();
	while(x>0)
	{
		int tmp=x%10;
		if(mp.count(tmp)==0)mp[tmp]=tmp;
		else return false;
		x/=10;
	}
	return true;
}
bool ck2(ll x)
{
	char s[15];
	bool vis[15];
	memset(vis,false,sizeof(vis));
	sprintf(s,"%lld",x);
	int len=strlen(s);
	
	int sum=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]-'0'==len)return false;
		sum+=s[i]-'0';
	}
	if(sum%len!=0)return false;
	int v=0;
	int n=0;
	while(n<len)
	{
		if(vis[v])return false;
		vis[v]=true;
		v+=s[v]-'0';
		v=v%len;
		n++;
	}
	return true;
}
int main()
{
	fin("runround.in");
	fout("runround.out");
	scanf("%lld",&N);
	while(N++)
	{
		if(!ck(N))continue;
		if(!ck2(N))continue;
		else break;
	}
	printf("%lld\n",N);
    return 0;
}
