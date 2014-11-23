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
#define PPF(a) push_front(a)
#define PF() pop_front()
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
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
int N,M;
int a[12][12],b[12][12];
void read()
{
	char tmp[100];
	gets(tmp);
	gets(tmp);
	for(int i=2,c=1;c<M;i+=2,c++)
		b[1][c]=tmp[i]-'0';
	for(int i=1;i<N;i++)
	{
		gets(tmp);
		for(int j=1,c=1;c<=M;j+=2,c++)
			a[i][c]=tmp[j]-'0';
		gets(tmp);
		for(int j=2,c=1;c<M;j+=2,c++)
			b[i+1][c]=tmp[j]-'0';
	}
	gets(tmp);		
}
#define HASH 30007
#define STATE 1000010
struct HASHMAP
{
	int val[STATE],sta[STATE],next[STATE],head[HASH],sz;
	inline void init()
	{
		MS(head,-1);
		sz=0;
	}
	inline int size()const
	{
		return this->sz;
	}
	inline int getsta(int idx)const
	{
		return this->sta[idx];
	}
	inline int getval(int idx)const
	{
		return this->val[idx];
	}
	inline void push(int st,int v)
	{
		int t=st%HASH;
		for(int p=head[t];~p;p=next[p])
		{
			if(st==sta[p])
			{
				val[p]=min(val[p],v);
				return ;
			}
		}
		val[sz]=v;
		sta[sz]=st;
		next[sz]=head[t];
		head[t]=sz++;
	}
}hs[2];
inline int change(int sta,int k,int c)
{
	return (sta&(2147483647^((1<<(2*(k+1)))-1)))|((sta&((1<<(2*k))-1))|(c<<(2*k)));
}
inline int DP()
{
	hs[0].init();hs[1].init();
	int flag=0;
	hs[flag].push(0,0);
	int ans=INF;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++,flag^=1)
		{
			//printf("%d %d\n",i,j);
			hs[flag^1].init();
			int sz=hs[flag].size();
			if(j==M)
			{
				for(int k=0;k<sz;k++)
				{
					int sta=hs[flag].getsta(k);
					int val=hs[flag].getval(k);
					//if(i==8)printf("no. %d sta %d val %d\n",k,sta,val);
					hs[flag^1].push(sta<<2,val);
					//if(i==8)puts("success");
				}
				continue;
			}
			for(int k=0;k<sz;k++)
			{
				int sta=hs[flag].getsta(k);
				int val=hs[flag].getval(k);
				//printf("sta %d val %d\n",sta,val);
				int left=(sta>>(j<<1))&3;
				int up  =(sta>>((j+1)<<1))&3;
				if(left==0&&up==0)
				{
					if(j+1==M)continue;
					sta=change(change(sta,j,1),j+1,2);
					hs[flag^1].push(sta,val);
				}
				else if(left==1&&up==1)
				{
					sta=change(change(sta,j,0),j+1,0);
					for(int q=j+2,p=1;q<=M+1;q++)
					{
						if((sta>>(q<<1))&1)p++;
						else if((sta>>(q<<1))&2)
						{
							p--;
							if(p==0)
							{
								sta=change(sta,q,1);
								break;
							}
						}
					}
					hs[flag^1].push(sta,val+a[i-1][j+1]+b[i][j]);
				}
				else if(left==2&&up==2)
				{
					sta=change(change(sta,j,0),j+1,0);
					for(int q=j-1,p=1;q>=0;q--)
					{
						if((sta>>(q<<1))&2)p++;
						else if((sta>>(q<<1))&1)
						{
							p--;
							if(p==0)
							{
								sta=change(sta,q,2);
								break;
							}
						}
					}
					hs[flag^1].push(sta,val+a[i-1][j+1]+b[i][j]);
				}
				else if(left==2&&up==1)
				{
					sta=change(change(sta,j,0),j+1,0);
					hs[flag^1].push(sta,val+a[i-1][j+1]+b[i][j]);
				}
				else if(left==1&&up==2)
				{
					if(i==N&&j+1==M)
					{
						sta=change(change(sta,j,0),j+1,0);
						if(sta)continue;
						ans=min(ans,val+a[i-1][j+1]+b[i][j]);
						hs[flag^1].push(sta,val+a[i-1][j+1]+b[i][j]);
					}
				}
				else 
				{
					if(left!=0&&up==0)
					{
						if(i<N)
						{
							hs[flag^1].push(sta,val+b[i][j]);
						}
						if(j+2<=M)
						{
							sta=change(change(sta,j,0),j+1,left);
							hs[flag^1].push(sta,val+b[i][j]);
							//printf(" %d\n",b[i][j]);
						}
					}
					else if(left==0&&up!=0)
					{
						if(j+2<=M)
						{
							hs[flag^1].push(sta,val+a[i-1][j+1]);
						}
						if(i<N)
						{
							sta=change(change(sta,j,up),j+1,0);
							hs[flag^1].push(sta,val+a[i-1][j+1]);
						}
					}
				}
			}
		}
	}
	return ans==INF?0:ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d%*c",&N,&M);
		read();
		printf("%d\n",DP());
	}
	return 0;
}

