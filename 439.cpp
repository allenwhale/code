#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define MS(s,v) memset(s,v,sizeof(s))
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int mp[10][10];
bool vis[10][10];
bool isin(int x,int y)
{
	return x>=0&&x<8&&y>=0&&y<8;
}
int main()
{
	char f[10],t[10];
	while(~scanf("%s %s",f,t))
	{
		MS(mp,0x3f);
		MS(vis,false);
		int fx=f[0]-'a',fy=f[1]-'1',tx=t[0]-'a',ty=t[1]-'1';
		mp[fx][fy]=0;
		queue< pair<int,int> >q;
		q.push(make_pair(fx,fy));
		vis[fx][fy]=true;
		while(!q.empty())
		{
			pair<int,int> tmp=q.front();
			q.pop();
			int x=tmp.first,y=tmp.second;
			//if(vis[x][y])continue;
			if(x==tx&&y==ty)break;
			//vis[x][y]=true;
			for(int i=0;i<8;i++)
			{
				int tox=x+dx[i],toy=y+dy[i];
				if(isin(x,y)&&!vis[tox][toy])
				{
					vis[tox][toy]=true;
					mp[tox][toy]=mp[x][y]+1;
					q.push(make_pair(tox,toy));
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",f,t,mp[tx][ty]);
	}
	//puts("end");
	return 0;
}

