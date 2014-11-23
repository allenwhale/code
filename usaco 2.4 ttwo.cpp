/*
ID: allenwh1
PROG: ttwo
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
char mp[15][15];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int fx,fy,cx,cy;
int fd=0,cd=0;
int fs=0,cs=0;
int t=0;
bool isin(int x,int y)
{
	return (!(x>=10||x<0||y>=10||y<0)&&mp[y][x]);
}
int solve()
{
	while(fs<=400&&cs<=400)
	{
		if(fx==cx&&fy==cy)break;
		if(isin(fx+dx[fd],fy+dy[fd]))
		{
			fx+=dx[fd],fy+=dy[fd],fs++;
		}
		else 
		{
			fd=(fd+1)%4;
		}
		if(isin(cx+dx[cd],cy+dy[cd]))
		{
			cx+=dx[cd],cy+=dy[cd],cs++;
		}
		else 
		{
			cd=(cd+1)%4;
		}
		t++;
	}
	if(fs<=400&&cs<=400)
	{
		return t;
	}
	else return 0;
}
int main()
{
	fin("ttwo.in");
	fout("ttwo.out");
	char s[15],p;
	memset(mp,false,sizeof(mp));
	for(int i=0;i<10;i++)
	{
		//printf("a\n");
		gets(s);
		for(int j=0;j<10;j++)
		{
			//scanf("%c",&mp[i][j]);
			p=s[j];
			if(p=='.')mp[i][j]=true;
			else if(p=='F')mp[i][j]=true,fx=j,fy=i;
			else if(p=='C')mp[i][j]=true,cx=j,cy=i;
			else if(p=='*')mp[i][j]=false;
		}
	}
	int ans=solve();
	printf("%d\n",ans);
    return 0;
}
