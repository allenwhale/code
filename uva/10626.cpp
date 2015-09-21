#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int dp[1010][210][110];
int find(int c,int n1,int n2,int n3)
{
	int &tmp=dp[n1][n2][n3];
	if(tmp!=-1)return tmp;
	if(c==0)return tmp=0;
	tmp=0x3f3f3f3f;
	if(n1>=8)tmp=min(tmp,find(c-1,n1-8,n2,n3)+8);
	if(n1>=3&&n2>=1)tmp=min(tmp,find(c-1,n1-3,n2-1,n3)+4);
	if(n1>=3&&n3>=1)tmp=min(tmp,find(c-1,n1-3,n2+1,n3-1)+4);
	if(n2>=3)tmp=min(tmp,find(c-1,n1+2,n2-2,n3)+2);
	if(n3>=1)tmp=min(tmp,find(c-1,n1+2,n2,n3-1)+1);
	return tmp;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int c,n1,n2,n3;
		scanf("%d %d %d %d",&c,&n1,&n2,&n3);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",find(c,n1,n2,n3));
	}
	return 0;
}