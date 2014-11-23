/*
ID: allenwh1
PROG: maze1
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
const int INF=9999999;
using namespace std;
int N,M;//n¾îmª½ 
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool mp[210][210];
int d[2][210][210];
int e[2][2];//0¾î1ª½
bool vis[210][210];
int ans=0;
bool isin(int x,int y)
{
	return !(x<0||y<0||x>N*2||y>M*2);
}
void BFS(int num,int x,int y)
{
	pair<int,int>pr;
	queue< pair<int,int> >q;
	d[num][x][y]=0;
	for(int i=0;i<4;i++)
	{
		if(isin(x+dx[i],y+dy[i])&&mp[y+dy[i]][x+dx[i]])
		{		
			d[num][x+dx[i]][y+dy[i]]=d[num][x][y]+1;
			q.push(make_pair(x+dx[i],y+dy[i]));
		}
	}
	vis[x][y]=true;
	while(!q.empty())
	{
		pr=q.front();
		q.pop();
		int xx=pr.first,yy=pr.second;
		if(vis[xx][yy])continue; 
		vis[xx][yy]=true;
		for(int i=0;i<4;i++)
		{
			if(isin(xx+dx[i],yy+dy[i])&&mp[yy+dy[i]][xx+dx[i]]&&!vis[xx+dx[i]][yy+dy[i]])
			{
				if(d[num][xx+dx[i]][yy+dy[i]]>d[num][xx][yy]+1)
				{
					d[num][xx+dx[i]][yy+dy[i]]=d[num][xx][yy]+1;
					q.push(make_pair(xx+dx[i],yy+dy[i]));
				}
			}
		}
	}
	return;
} 
int main()
{
	fin("maze1.in");
	fout("maze1.out");
	memset(mp,false,sizeof(mp));
	scanf("%d %d",&N,&M);
	getchar();
	int t=0;
	char s[100];
	for(int i=0;i<M*2+1;i++)
	{
		gets(s);
		for(int j=0;j<N*2+1;j++)
		{
			if(s[j]==' ') mp[i][j]=true;
			else mp[i][j]=false;
			if(s[j]==' '&&(j==0||j==N*2))e[t][0]=j,e[t++][1]=i;
			else if(s[j]==' '&&(i==0||i==M*2))e[t][0]=j,e[t++][1]=i;
		}
	}
	memset(d,INF,sizeof(d));
	memset(vis,false,sizeof(vis));
	BFS(0,e[0][0],e[0][1]);
	memset(vis,false,sizeof(vis));
	BFS(1,e[1][0],e[1][1]);
	for(int i=0;i<M*2+1;i++)
	{
		for(int j=0;j<N*2+1;j++)
		{
			if(mp[i][j])
			{ 
				ans=max(ans,min(d[0][j][i],d[1][j][i]));
			} 
		}
	}
	printf("%d\n",(ans+1)/2);
    return 0;
}
