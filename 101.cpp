#include <stdio.h>
int main()
{
	int block[30][30]={0},pos[30][2]={0},top[30]={0};
	int n;
	while(~scanf("%d",&n))
	{
		int i,j,k;
		for(i=0;i<n;i++)
		{
			block[i][1]=i;
			top[i]=1;
			pos[i][0]=i;
			pos[i][1]=1;
		}
		char s1[10],s2[10];
		int fr,to;
		while(scanf("%s",s1))
		{
			
			if(s1[0]=='q')break;
			//printf("%s\n",s1);
			scanf("%d %s %d",&fr,s2,&to);
			int fx=pos[fr][0],fy=pos[fr][1];
			int tx=pos[to][0],ty=pos[to][1];
			if(fx==tx)continue;
			if(s1[0]=='m')
			{
				if(s2[1]=='n')
				{
					for(i=top[fx];i>fy;i--,top[fx]--)
					{
						block[block[fx][i]][1]=block[fx][i];
						top[block[fx][i]]=1;
						pos[block[fx][i]][0]=block[fx][i];
						pos[block[fx][i]][1]=1;
						block[fx][i]=0;
					}
					for(i=top[tx];i>ty;i--,top[tx]--)
					{
						block[block[tx][i]][1]=block[tx][i];
						top[block[tx][i]]=1;
						pos[block[tx][i]][0]=block[tx][i];
						pos[block[tx][i]][1]=1;
						block[tx][i]=0;
					}
					pos[fr][0]=tx;
					pos[fr][1]=ty+1;
					top[tx]=ty+1;
					top[fx]=fy-1;
					block[tx][ty+1]=fr;
					block[fx][fy]=0;
				}
				else
				{
					for(i=top[fx];i>fy;i--,top[fx]--)
					{
						block[block[fx][i]][1]=block[fx][i];
						top[block[fx][i]]=1;
						pos[block[fx][i]][0]=block[fx][i];
						pos[block[fx][i]][1]=1;
						block[fx][i]=0;
					}
					pos[fr][0]=tx;
					pos[fr][1]=top[tx]+1;
					block[fx][fy]=0;
					top[fx]=fy-1;
					block[tx][top[tx]+1]=fr;
					top[tx]++;
				}
			}
			else
			{
				if(s2[1]=='n')
				{
					for(i=top[tx];i>ty;i--,top[tx]--)
					{
						block[block[tx][i]][1]=block[tx][i];
						top[block[tx][i]]++;
						pos[block[tx][i]][0]=block[tx][i];
						pos[block[tx][i]][1]=1;
						block[tx][i]=0;
					}
					for(i=fy;i<=top[fx];i++,top[tx]++)
					{
						block[tx][top[tx]+1]=block[fx][i];
						pos[block[fx][i]][0]=tx;
						pos[block[fx][i]][1]=top[tx]+1;
						block[fx][i]=0;
					}
					top[fx]=fy-1;
				}
				else
				{
					for(i=fy;i<=top[fx];i++,top[tx]++)
					{
						block[tx][top[tx]+1]=block[fx][i];
						pos[block[fx][i]][0]=tx;
						pos[block[fx][i]][1]=top[tx]+1;
						block[fx][i]=0;
					}
					top[fx]=fy-1;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d:",i);
			for(j=1;j<=top[i];j++)
			{
				printf(" %d",block[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}
