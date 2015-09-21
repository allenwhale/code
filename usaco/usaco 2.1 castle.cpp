/*
ID: allenwh1
PROG: castle
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;
#define m_p(a,b) make_pair(a,b)
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define max(a,b) a>b?a:b
#define ms(a) memset(a,false,sizeof(a))
#define st first
#define nd second 
int mx=0,mx2=0;
int a,b;
bool vis[110][110];
bool mp[110][110];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M;
void in(int i,int j,int n)
{
	if(n==1)mp[i][j]=mp[i][j+1]=mp[i+1][j]=true;
	else if(n==3)mp[i][j]=mp[i][j+1]=mp[i+1][j]=true;
	else if(n==5)mp[i][j]=mp[i+1][j]=true,mp[i][j+1]=false;
	else if(n==6)mp[i][j]=mp[i+1][j]=true,mp[i][j+1]=false;
	else if(n==7)mp[i][j]=mp[i+1][j]=true,mp[i][j+1]=false;
	else if(n==9)mp[i][j]=mp[i][j+1]=true,mp[i+1][j]=false;
	else if(n==10)mp[i][j]=mp[i][j+1]=true,mp[i+1][j]=false;
	else if(n==11)mp[i][j]=mp[i][j+1]=true,mp[i+1][j]=false;
	else if(n==12)mp[i][j]=true,mp[i+1][j]=mp[i][j+1]=false;
	else if(n==13)mp[i][j]=true,mp[i+1][j]=mp[i][j+1]=false;
	else if(n==14)mp[i][j]=true,mp[i+1][j]=mp[i][j+1]=false;
	else if(n==15)mp[i][j]=true,mp[i][j+1]=mp[i+1][j]=false;
	else if(n==2)mp[i][j]=mp[i][j+1]=mp[i+1][j]=true;
	else if(n==8)mp[i][j]=mp[i][j+1]=true,mp[i+1][j]=false;
	else if(n==4)mp[i][j]=mp[i+1][j]=true,mp[i][j+1]=false;
	else if(n==0)mp[i][j]=mp[i][j+1]=mp[i+1][j]=true;
	return;
}
int BFS(int i,int j)
{
	int size=0;
	pair<int,int>pr;
	queue< pair<int,int> >q;
	q.push(m_p(i,j));
	while(!q.empty())
	{
		pr=q.front();
		q.pop();
		if(vis[pr.st][pr.nd])continue;
		if(pr.st&1 && pr.nd&1)size++;
		vis[pr.st][pr.nd]=true;
		for(int k=0;k<4;k++)
		{
			if(!vis[pr.st+dy[k]][pr.nd+dx[k]]&&mp[pr.st+dy[k]][pr.nd+dx[k]])
			{
				q.push(m_p(pr.st+dy[k],pr.nd+dx[k]));
			}
		}
	}
	mx=max(mx,size);
	return size;
}
void BFS2()
{
	for(int i=1;i<2*M+1;i++)
	{
		for(int j=1;j<2*N+1;j++)
		{
			if(!mp[i][j])
			{
				ms(vis);
				mp[i][j]=true;
				int size=BFS(i,j);
				if(size>mx2)
				{													
					a=i,b=j;
					mx2=size;
				}
				if(size==mx2)
				{
					if(b>j)
					{
						b=j,a=i;
					}
					else if(b==j&&a<i)
					{
						b=j,a=i;
					}
				}
				mp[i][j]=false;
			}
		}
	}
} 
int main()
{
	fin("castle.in");
	fout("castle.out");
	scanf("%d %d",&N,&M);
	ms(vis);
	ms(mp);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			int state;
			scanf("%d",&state);
			in(i*2+1,j*2+1,state);
		}
	}
	int num=0;
	for(int i=0;i<2*M+1;i++)
	{
		for(int j=0;j<2*N+1;j++)
		{
			if(!vis[i][j]&&mp[i][j])BFS(i,j),num++;
		}
	}
	printf("%d\n%d\n",num,mx);
	BFS2();
	printf("%d\n",mx2);
	char c;
	if(a&1)b--,c='E';
	else if(b&1)a++,c='N'; 
	printf("%d %d %c\n",(a+1)/2,(b+1)/2,c);
    return 0;
}
