#include <stdio.h>
#include <iostream>
#include <complex>
#include <math.h>
#define INF 1e9
using namespace std;
typedef double db;
typedef complex<db> cd;
cd n[100];
db l[100][100];
bool vis[100]={false};
int main()
{
	db x,y;
	int N=0;
	while(~scanf("%lf %lf",&x,&y))
	{
		n[N++]=cd (x,y);
	}
	for(int i=0;i<N;i++)
	{
		l[i][i]=INF;
		for(int j=i+1;j<N;j++)
		{
			cd vec=n[i]-n[j];
			l[i][j]=l[j][i]=abs(vec);
		}
	}
	db ans=0.0;
	int now=0,cnt=1;
	db mx=0.0;
	vis[0]=true;
	while(cnt<N)
	{
		int index;
		db mn=1e9;
		for(int i=0;i<N;i++)
		{	
			if(!vis[i])
			{
				if(mn>l[now][i])
				{
					mn=l[now][i];
					index=i;
				}
			}
		}
		vis[index]=true;
		ans+=mn;
		mx=max(mx,mn);
		now=index;
		cnt++;
	}
	cd vec=n[0]-n[now];
	db ll=abs(vec);
	ans+=ll;
	mx=max(mx,ll);
	ans-=mx;
	printf("%lf\n",ans);
	return 0;
}
