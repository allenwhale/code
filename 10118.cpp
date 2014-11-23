#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
int N;
int s[4][50];
int dp[50][50][50][50];
int find(int b,int c,int n1,int n2,int n3,int n4)
{
	int &tmp=dp[n1][n2][n3][n4];
	if(tmp!=-1)return tmp;
	if(c==5)return tmp=0;
	tmp=0;
	if(n1)
	{
		if(b&(1<<s[0][n1]))
		{
			tmp=max(tmp,find(b^(1<<s[0][n1]),c-1,n1-1,n2,n3,n4)+1);
		}
		else
		{
			tmp=max(tmp,find(b|(1<<s[0][n1]),c+1,n1-1,n2,n3,n4));
		}
	}
	if(n2)
	{
		if(b&(1<<s[1][n2]))
		{
			tmp=max(tmp,find(b^(1<<s[1][n2]),c-1,n1,n2-1,n3,n4)+1);
		}
		else
		{
			tmp=max(tmp,find(b|(1<<s[1][n2]),c+1,n1,n2-1,n3,n4));
		}
	}
	if(n3)
	{
		if(b&(1<<s[2][n3]))
		{
			tmp=max(tmp,find(b^(1<<s[2][n3]),c-1,n1,n2,n3-1,n4)+1);
		}
		else
		{
			tmp=max(tmp,find(b|(1<<s[2][n3]),c+1,n1,n2,n3-1,n4));
		}
	}
	if(n4)
	{
		if(b&(1<<s[3][n4]))
		{
			tmp=max(tmp,find(b^(1<<s[3][n4]),c-1,n1,n2,n3,n4-1)+1);
		}
		else
		{
			tmp=max(tmp,find(b|(1<<s[3][n4]),c+1,n1,n2,n3,n4-1));
		}
	}
	//printf("%d %d %d %d %d %d %d\n",b,c,n1,n2,n3,n4,tmp);
	return tmp;
}
int main()
{
	while(~scanf("%d",&N)&&N)
	{
		for(int i=N;i>=1;i--)
		{
			for(int j=0;j<4;j++)
			{
				scanf("%d",&s[j][i]);
			}
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",find(0,0,N,N,N,N));
	}
	return 0;
}