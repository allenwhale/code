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

int deg[30];
bool vis[30];
int p[30];
void init()
{
	for(int i=0;i<30;i++)p[i]=i;
}
int find(int a)
{
	return p[a]==a?a:p[a]=find(p[a]);
}
void U(int a,int b)
{
	p[find(b)]=find(a);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		MS(deg,0);
		MS(vis,false);
		int N;scanf("%d",&N);
		int st=-1;
		while(N--)
		{
			char s[1010];
			scanf("%s",s);
			deg[st=(s[0]-'a')]--;
			deg[s[strlen(s)-1]-'a']++;
			U(s[0]-'a',s[strlen(s)-1]-'a');	
			vis[s[0]-'a']=vis[s[strlen(s)-1]-'a']=true;		
		}
		bool tf=true;
		int n1=0,n2=0;
		for(int i=0;i<26;i++)
		{
			if(deg[i]!=0)
			{
				if(deg[i]==-1)n1++;
				else if(deg[i]==1)n2++;
				else tf=false;
			}
		}
		for(int i=0;i<26;i++)
		{
			if(vis[i]&&find(i)!=find(st))tf=false;
		}
		if(!(!tf||(n1+n2>2)))puts("Ordering is possible.");
		else puts("The door cannot be opened.");
	}
	return 0;
}

