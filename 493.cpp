#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
map<pair<int,int> ,int>mp;
int X[510000],Y[510000];
int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}
pair<int,int> make(int a,int b)
{
	if(b==0)return make_pair(0,1);
	int g=gcd(abs(a),abs(b));
	return make_pair(((a*b<0)?-1:1)*abs(b)/g,abs(a)/g);
}
void prepare()
{
	//X[0]=Y[0]=0;
	int x=0,y=0;
	int cnt=0;
	for(int i=1;i<2237&&cnt<500010;i++)
	{
		for(int j=0;j<i&&cnt<500010;j++)
		{
			if(i&1)
			{
				y++;
			}
			else
			{
				y--;
			}
			if(x)
			{
				pair<int,int> tmp=make(x,y);
				if(mp.count(tmp))continue;
				mp[tmp]=1;
				X[cnt]=tmp.second,Y[cnt++]=tmp.first;
			}
		}
		for(int j=0;j<i&&cnt<500010;j++)
		{
			if(i&1)
			{
				x++;
			}
			else
			{
				x--;
			}
			if(x)
			{
				pair<int,int> tmp=make(x,y);
				if(mp.count(tmp))continue;
				mp[tmp]=1;
				X[cnt]=tmp.second,Y[cnt++]=tmp.first;
			}
		}
	}
}
int main()
{
	prepare();
	int N;
	while(~scanf("%d",&N))
	{
		printf("%d / %d\n",Y[N],X[N]);
	}
	return 0;
}

