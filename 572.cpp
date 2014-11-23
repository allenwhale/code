#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
char s[110][110];
bool vis[110][110];
int N,M;
typedef pair<int,int> PI;
#define MP make_pair
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};
bool isin(int x,int y)
{
    return x>=0&&x<N&&y>=0&&y<M;
}
void BFS(int x,int y)
{
    queue<PI>q;
    vis[x][y]=true;
    q.push(MP(x,y));
    while(!q.empty())
    {
        PI tmp=q.front();q.pop();
        for(int i=0;i<8;i++)
        {
            int tx=tmp.first+dx[i],ty=tmp.second+dy[i];
            if(isin(tx,ty)&&vis[tx][ty]==false&&s[tx][ty]=='@')
            {
                vis[tx][ty]=true;
                q.push(MP(tx,ty));   
            }
        }
    }
}
int main()
{
    while(~scanf("%d %d%*c",&N,&M)&&N&&M)
    {
        for(int i=0;i<N;i++)gets(s[i]);
        memset(vis,false,sizeof(vis));
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(s[i][j]=='@'&&vis[i][j]==false)
                {
                    BFS(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
