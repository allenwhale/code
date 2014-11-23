#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int N;
int mp[15][15];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool num[1010];
bool num2[1010];
int maxlen=0;
inline bool isin(int x,int y)
{
	return x>=0&&y>=0&&x<N&&y<N;
}
inline int clac()
{
	//memcpy(num2,num,sizeof(num));
	int res=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!num[mp[i][j]])
			{
				//num2[mp[i][j]]=true;
				res++;
			}
		}
	}
	return res;
}
void dfs(int x,int y,int l)
{
	num[mp[x][y]]=true;
	maxlen=max(maxlen,l);
	if(l+clac()<=maxlen)return;
	if(y-1>=0&&num[mp[x][y-1]]==false)dfs(x,y-1,l+1);
	if(x+1<N&&num[mp[x+1][y]]==false)dfs(x+1,y,l+1);
	if(y+1<N&&num[mp[x][y+1]]==false)dfs(x,y+1,l+1);
	if(x-1>=0&&num[mp[x-1][y]]==false)dfs(x-1,y,l+1);
	num[mp[x][y]]=false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		maxlen=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				//memset(vis,false,sizeof(vis));
				//memset(num,false,sizeof(num));
				dfs(i,j,1);
			}
		}
		printf("%d\n",maxlen);
		if(T)puts("");
	}
	return 0;
}
