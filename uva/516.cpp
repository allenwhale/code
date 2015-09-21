#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int p[5500];
int pn=0;
void makeprime()
{
	p[pn++]=2,p[pn++]=3;
	for(int i=5;i<=128*128*2;i+=2)
	{
		bool tf=true;
		for(int j=0;j<pn&&p[j]*p[j]<=i&&tf;j++)
		{
			if(i%p[j]==0)tf=false;
		}
		if(tf)p[pn++]=i;
	}
}
void make(int x)
{
	int T=0;
	int i=pn-1;
	while(x<p[i])i--;
	for(;i>=0;i--)
	{
		int cnt=0;
		while(x%p[i]==0)
		{
			cnt++;
			x/=p[i];
		}
		if(cnt)printf("%s%d %d",T++?" ":"",p[i],cnt);
	}
	puts("");
}
int POW(int a,int b)
{
	int res=1;
	while(b--)res*=a;
	return res;
}
int main()
{
	makeprime();
	char s[1000];
	while(gets(s)!=NULL&&s[0]!='0')
	{
		//puts(s);
		char *ptr=strtok(s," ");
		//puts(ptr);
		int pre=1;
		while(ptr!=NULL)
		{
			int a,b;
			sscanf(ptr,"%d",&a);
			ptr=strtok(NULL," ");
			sscanf(ptr,"%d",&b);
			ptr=strtok(NULL," ");
			//printf("%d %d\n",a,b);
			pre*=(int)POW(a,b);
		}
		//puts("read");
		pre-=1;
		//printf("%d\n",pre);
		make(pre);
	}
	return 0;
}

