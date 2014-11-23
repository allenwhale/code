/*
ID: allenwh1
PROG: cowtour
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <deque>
#include <iostream>
#include <deque>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
#define d(a,b) sqrt((dq[a].first-dq[b].first)*(dq[a].first-dq[b].first)+(dq[a].second-dq[b].second)*(dq[a].second-dq[b].second))
typedef double db;
deque< pair<db,db> >dq;
int N;
const db INF=1e9;
db dis[200][200];
db mx[200];
int main()
{
	fin("cowtour.in");
	fout("cowtour.out");
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			dis[i][j]=INF;
		}
	}
	for(int i=0;i<N;i++)
	{
		db x,y;
		scanf("%lf %lf",&x,&y);
		dq.push_back(make_pair(x,y));
	} 
	getchar();
	char s[200];
	for(int i=0;i<N;i++)
	{
		gets(s);
		for(int j=0;j<N;j++)
		{
			char t;
			t=s[j];
			if(t=='1')
			{
				if(dis[i][j]==INF)
				{
					dis[i][j]=dis[j][i]=d(i,j);
				}
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		dis[i][i]=0.0;
	} 
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(k==j||k==i)continue;
				if(dis[i][k]+dis[k][j]<dis[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	memset(mx,0,sizeof(mx));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(dis[i][j]!=INF)mx[i]=max(mx[i],dis[i][j]);
		}
	}
	db mn=1e9;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(dis[i][j]==INF)
			{
				db newd=d(i,j);
				mn=min(mn,newd+mx[i]+mx[j]);
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		mn=max(mn,mx[i]);
	}
	printf("%.6lf\n",mn);
    return 0;
}
