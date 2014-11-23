#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <ctype.h>
#include <complex>
#define FF first
#define SS second
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define PPB() pop_back()
#define PF(a) push_front(a)
#define PPF() pop_front()
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
#define lb(x) ((x)&(-(x)))
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
ll K,mp[2010][2010];
ll bit[2010][2010];
int N;

void add(int x,int y,ll v)
{
	for(int i=x;i<=N;i+=lb(i))
	{
		for(int j=y;j<=N;j+=lb(j))
		{
			bit[i][j]+=v;
		}
	}
}
ll cnt(int x,int y)
{
	ll res=0ll;
	for(int i=x;i>0;i-=lb(i))
	{
		for(int j=y;j>0;j-=lb(j))
		{
			res+=bit[i][j];
		}
	}
	return res;
}
ll query(int x1,int y1,int x2,int y2)
{
	int mnx=min(x1,x2),mxx=max(x1,x2),mny=min(y1,y2),mxy=max(y1,y2);
	return cnt(mxx,mxy)-cnt(mnx-1,mxy)-cnt(mxx,mny-1)+cnt(mnx-1,mny-1);
}
void print(int x1,int y1,int x2,int y2)
{
	//printf("print %d %d %d %d\n",x1,y1,x2,y2);
	for(int i=y1;i<=y2;i++)
	{
		//printf("  %d\n",i);
		ll s;
		s=query(x1,i,x2,y2);
		//printf("%d %d %d %d %d\n",x1,i,x2,y2,s);
		if(s>=K&&s<=2*K)
		{
			printf("%d %d %d %d\n",i,x1,y2,x2);
			return ;
		}
		s=query(x1,i,x2,i);
		//printf("%d %d %d %d %d\n",x1,i,x2,i,s);
		if(s>=K&&s<=2*K)
		{
			printf("%d %d %d %d\n",i,x1,i,x2);
			return;
		}
		else if(s<K);
		else if(s>2*K)
		{
			for(int j=x1;j<=x2;j++)
			{
				//printf("%d %d %d %d %d\n",j,i,j,i,mp[j][i]);
				if(mp[j][i]>=K&&mp[j][i]<=K*2)
				{
					printf("%d %d %d %d\n",i,j,i,j);
					return ;
				}
			}
			ll tmp=0;
			for(int j=x1;j<=x2;j++)	
			{
				tmp+=mp[j][i];
				//printf("%d ",tmp);
				if(tmp>=K&&tmp<=K*2)
				{
					printf("%d %d %d %d\n",i,x1,i,j);
					return ;
				}
			}
			//puts("");
		}
	}
}
void find()
{
	int L[2010]={0},R[2010]={0},l[2010]={0},r[2010]={0},up[2010]={0};
	MS(up,0);
	bool ok[2010]={false};
	int x1=0,x2=0,y1=0,y2=0;
	ll ans=0;
	for(int i=1;i<=N;i++)
	{
		//printf(" %d\n",i);
		int tl=1;
		for(int j=1;j<=N;j++)
		{
			if(mp[i][j]<=K*2)l[j]=tl;
			else l[j]=j,tl=j+1;
		}
		int tr=N+1;
		for(int j=N;j>=1;j--)
		{
			if(mp[i][j]<=K*2)r[j]=tr;
			else r[j]=j,tr=j;
		}
		//for(int j=1;j<=N;j++)
		//	printf(" %d",l[j]);
	//	puts("");
		//puts("f");
		for(int j=1;j<=N;j++)
		{
			//printf("%d\n",j);
			if(mp[i][j]>2*K)
			{
				ok[j]=false;
				up[j]=0;
				continue;
			}
			else
			{
				int ttl,ttr;
				if(ok[j])ttl=max(l[j],L[j]),ttr=min(r[j],R[j]);
				else ttl=l[j],ttr=r[j];
				up[j]++;
				ok[j]=true;
				ll ta=query(i-up[j]+1,ttl,i,ttr-1);
			//	printf("%d %d %d %d\n",i-up[j]+1,ttl,i,ttr-1);
				//puts("q");
				if(ans<ta)
				{
					ans=ta;
					x1=i-up[j]+1,y1=ttl,x2=i,y2=ttr-1;
					//printf("update %d %d %d %d %d\n",x1,y1,x2,y2,ta);
				}
				L[j]=ttl,R[j]=ttr;
			}
		}
	}
//	/printf(__lld" %d %d %d %d\n",ans,x1,y1,x2,y2);
	if(ans<K)puts("NIE");
	else print(x1,y1,x2,y2);
}
inline ll getll(){    // getchar input integer
	char s,d;
	while(s=getchar(),s==' '||s=='\n');
	ll x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}
int main()
{
	//puts("27 25 50 49");
	//return 0;
	scanf(__lld" %d",&K,&N);
	
	MS(bit,0);
	MS(mp,0);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			//scanf(__lld,&mp[i][j]);
			mp[i][j]=getll();
			add(i,j,mp[i][j]);
		}
	}
	//puts("in");
	find();
	return 0;
}

