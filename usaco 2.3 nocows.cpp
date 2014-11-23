/*
ID: allenwh1
PROG: nocows
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define MOD %=9901
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
int tree[110][220];
int smtr[110][220];
int n,k,c;
int main()
{
	fin("nocows.in");
	fout("nocows.out");
	scanf("%d %d",&n,&k);
	memset(tree,0,sizeof(tree));
	memset(smtr,0,sizeof(smtr));
	tree[1][1]=1;
	for(int i=2;i<=k;i++)
	{
		for(int j=1;j<=n;j+=2)
		{
			for(int k=1;k<=j-1-k;k+=2)
			{
				if(k!=j-1-k)c=2;
				else c=1;
				tree[i][j]+=c*(smtr[i-2][k]*tree[i-1][j-1-k]
								+smtr[i-2][j-1-k]*tree[i-1][k]
								+tree[i-1][k]*tree[i-1][j-1-k]);
				tree[i][j] MOD;
			}
		}
		for(int k=0;k<=n;k++)
		{
			smtr[i-1][k]+=tree[i-1][k]+smtr[i-2][k];
			smtr[i-1][k] MOD;
		}
	}
	printf("%d\n",tree[k][n]);
    return 0;
}
