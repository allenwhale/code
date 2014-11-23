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
struct S
{
	char s[5][5];
}soy[15];
struct MAT
{
	int d[15][15];
	MAT()
	{
		MS(d,0);
	}
};
MAT mul(MAT a,MAT b)
{
	MAT c=MAT();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			ll tmp=0;
			for(int k=0;k<N;k++)
			{
				tmp+=(ll)a.d[i][k]*(ll)b.d[k][j];
				tmp%=1000000007;
			}
			c.d[i][j]=tmp;
		}
	}
	return c;
}
bool isok(int a,int b)
{
	for(int i=0;i<3;i++)
	{
		if(soy[a].s[i][2]=='1'&&soy[b].s[i][0]=='1')return false;
	}
	return true;
}
bool check(int a)
{
	for(int i=0;i<3;i++)
	{
		if(soy[a].s[i][0]=='1'&&soy[a].s[i][1]=='1')return false;
		if(soy[a].s[i][1]=='1'&&soy[a].s[i][2]=='1')return false;
		if(soy[a].s[0][i]=='1'&&soy[a].s[1][i]=='1')return false;
		if(soy[a].s[1][i]=='1'&&soy[a].s[2][i]=='1')return false;
	}
	return true;
}
int main()
{
	MAT mat=MAT();
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%s",soy[i].s[j]);
		}
	}
	for(int i=0;i<N;i++)
	{\
		if(check(i)) 
		for(int j=0;j<N;j++)
		{
			if(check(j)&&isok(i,j))mat.d[i][j]=1;
		}
	}
	MAT ans=MAT();
	for(int i=0;i<N;i++)
		if(check(i))ans.d[i][i]=1;
	M--;
	while(M)
	{
		if(M&1)ans=mul(ans,mat);
		mat=mul(mat,mat);
		M>>=1;
	}
	ll tans=0;
	for(int i=0;i<N;i++)
	{
		if(check(i))
		for(int j=0;j<N;j++)
		{
			tans+=(ll)ans.d[i][j];
			tans%=1000000007ll;
		}
	}
	printf(__lld"\n",tans);
	return 0;
}

