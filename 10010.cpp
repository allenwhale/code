#include <stdio.h>
#include <ctype.h>
#include <string.h>
char s[60][60];
char k[30][60];
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,1,-1,0,1,-1,0};
int N,M,K; 
int isin(int x,int y)
{
	return x>=0&&y>=0&&x<N&&y<M;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++)
		{
			scanf("%s",s[i]);
			for(int j=0;j<M;j++)
			{
				s[i][j]=tolower(s[i][j]);
			}
		}
		scanf("%d",&K);
		for(int i=0;i<K;i++)
		{
			scanf("%s",k[i]);
			for(int j=0;k[i][j];j++)
			{
				k[i][j]=tolower(k[i][j]);
			}
		}
		for(int i=0;i<K;i++)
		{
			int len=strlen(k[i]);
			for(int j=0;j<N;j++)
			{
				for(int kk=0;kk<M;kk++)
				{
					if(s[j][kk]!=k[i][0])continue;
					int x=j,y=kk;
					for(int l=0;l<8;l++)
					{
						int m;
						for(m=0;m<len;m++)
						{
							int tx=x+dx[l]*m,ty=y+dy[l]*m;
							if(isin(tx,ty))
							{
								if(s[tx][ty]!=k[i][m])break;
							}
							else break;
						}
						if(m==len)
						{
							//printf("%c %c\n",s[x][y]);
							printf("%d %d\n",x+1,y+1);
							goto end;
						}
					}
				}
			}
			end:;
		}
		if(T)puts("");
	}
	return 0;
}
