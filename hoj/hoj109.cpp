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
#include <time.h>
using namespace std;
typedef long long ll;
typedef complex<int> cI;
typedef complex<double> cD;
typedef pair<int,int> pI;
typedef pair<double,double>pD;
vector<int>vc[300];
int p[300];
int dis[300][300];
int N,M;
void change(int &ANS)
{
	bool tf=true;
	//printf("pre %d\n",ANS);
	while(tf)
	{
		tf=false;
		for(int i=0;i<N*M;i++)
		{
			for(int j=0;j<N*M;j++)
			{
				int tmp=ANS;
				foreach(it,vc[i])
				{
					if(*it==j)continue;
					tmp-=dis[p[i]][p[*it]];
					tmp+=dis[p[j]][p[*it]];
				}
				foreach(it,vc[j])
				{
					if(*it==i)continue;
					tmp-=dis[p[j]][p[*it]];
					tmp+=dis[p[i]][p[*it]];
				}
				if(tmp<ANS)
				{
					ANS=tmp;
					swap(p[i],p[j]);
					tf=true;
				}
				//printf("%d %d %d %d\n",i,p[i],j,p[j]);
				//printf("now ANS %d\n",ANS);
				//system("pause");
			}
		}
		
	}
}
void init()
{
	for(int i=0;i<290;i++)vc[i].clear();
}
int main()
{
	srand(clock());
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d %d",&N,&M);
		for(int i=0;i<N*M;i++)
		{
			for(int j=i;j<N*M;j++)
			{
				int ix,iy,jx,jy;
				ix=i/M,iy=i%M;
				jx=j/M,jy=j%M;
				dis[i][j]=dis[j][i]=(ix-jx)*(ix-jx)+(iy-jy)*(iy-jy);
			}
		}
		for(int i=0;i<N*M-1;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			a--,b--;
			vc[a].PB(b);
			vc[b].PB(a);
		}
		for(int i=0;i<N*M;i++)
			p[i]=i;
		int ans=INF;
		for(int r=0;r<100;r++)	
		{
			//printf(" %d\n",r);
			random_shuffle(p,p+N*M);
			int tans=0;
			for(int i=0;i<N*M;i++)
			{
				foreach(it,vc[i])
				{
					if(i<*it)tans+=dis[p[i]][p[*it]];
				}
			}
			change(tans);
			ans=min(ans,tans);
		}
		printf("%d\n",ans);
	}
	return 0;
}

