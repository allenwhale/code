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
#define HASH 30007
#define STATE 1000010
struct HASH_MAP
{
	int head[HASH],sz;
	int next[STATE],sta[STATE];
	ll val[STATE]; 
	inline void init()
	{
		MS(this->head,-1);
		this->sz=0;
	}
	inline int size()const
	{
		return this->sz;
	}
	inline int getsta(int idx)const
	{
		return this->sta[idx];
	}
	inline ll getval(int idx)const
	{
		return this->val[idx];
	}
	inline void push(int st,ll v)
	{
		int t=st%HASH;
		for(int p=head[t];~p;p=next[p])
		{
			if(st==sta[p])
			{
				val[p]+=v;
				return ;
			}
		}
		val[sz]=v;
		sta[sz]=st;
		next[sz]=head[t];
		head[t]=sz++;
	}
}hs[2];
int N,M;
char mp[13][13];
int ex,ey;
void read()
{
	MS(mp,'.');
	for(int i=1;i<=N;i++)
		scanf("%s",mp[i]+1);
	for(int i=2;i<=M-1;i++)
		mp[N+1][i]='#';
	mp[N+1][M+1]=mp[N+2][M+1]='\0';
	N+=2;

}
void find()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(mp[i][j]=='.')ex=i,ey=j;
		}
	}
}
inline int change(int sta,int k,int c)
{
	return (sta&(2147483647^((1<<(2*(k+1)))-1)))|((sta&((1<<(2*k))-1))|(c<<(2*k)));
}
ll DP()
{
	ll ans=0ll;
	hs[0].init();
	hs[1].init();
	int flag=0;
	hs[flag].push(0,1);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=M;j++,flag^=1)
		{
			hs[flag^1].init();
			int sz=hs[flag].size();
			//printf(" %d %d %d\n",i,j,sz);
			if(j==M)
			{
				for(int k=0;k<sz;k++)
				{
					int sta=hs[flag].getsta(k);
					int val=hs[flag].getval(k);
					hs[flag^1].push(sta<<2,val);
				}
				continue;
			}
			for(int k=0;k<sz;k++)
			{
				int sta=hs[flag].getsta(k);
				int val=hs[flag].getval(k);
				int left=(sta>>(j<<1))&3;
				int up  =(sta>>((j+1)<<1))&3;
				//printf("sta %d left %d up %d\n",sta,left,up);
				if(mp[i][j+1]=='.')
				{
					if(left==0&&up==0)
					{
						if(j==M-1)continue;
						sta=change(change(sta,j,2),j+1,1);
						hs[flag^1].push(sta,val);
						//printf("turn %d\n",sta);
					}
					else if(left==1&&up==1)
					{
						sta=change(change(sta,j,0),j+1,0);
						for(int q=j-1,p=1;q>=0;q--)
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
						hs[flag^1].push(sta,val);
						//printf("turn %d\n",sta);
					}
					else if(left==2&&up==2)
					{
						if(j+1>M)continue;
						sta=change(change(sta,j,0),j+1,0);
						for(int q=j+2,p=1;q<=M+1;q++)
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
						hs[flag^1].push(sta,val);
						//printf("turn %d\n",sta);
					}
					else if(left==1&&up==2)
					{
						sta=change(change(sta,j,0),j+1,0);
						hs[flag^1].push(sta,val);
						//printf("turn %d\n",sta);
					}
					else if(left==2&&up==1)
					{
						if(i==ex&&j+1==ey)
						{
							sta=change(change(sta,j,0),j+1,0);
							if(sta)continue;
							hs[flag^1].push(sta,val);
							ans+=val;
							//printf("val %d\n",val);
							//printf("turn %d\n",sta);
						}
					}
					else
					{
						if(left!=0&&up==0)
						{
							if(i<N)
							{
								hs[flag^1].push(sta,val);
								//printf("turn %d\n",sta);
							}
							if(j+2<=M)
							{
								sta=change(change(sta,j,0),j+1,left);
								hs[flag^1].push(sta,val);
								//printf("turn %d\n",sta);
							}
						}
						else if(left==0&&up!=0)
						{
							if(j+2<=M)
							{
								hs[flag^1].push(sta,val);
								//printf("turn %d\n",sta);
							}
							if(i<N)
							{
								sta=change(change(sta,j,up),j+1,0);
								hs[flag^1].push(sta,val);
								//printf("turn %d\n",sta);
							}
						}
					}
				}
				else
				{
					if(up==0&&left==0)
					{
						hs[flag^1].push(sta,val);
						//printf("turn %d\n",sta);
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	while(~scanf("%d %d",&N,&M)&&N&&M)
	{
		read();
		//puts("read");
		find();
		//puts("find");
		ll ans=DP();
		//puts("DP");
		printf(__lld"\n",ans);
	}
	return 0;
}

