#include <stdio.h>//1g2b3c
typedef long long ll;

int main()
{
	ll s[4][4];
	ll ans;
	while(~scanf("%lld",&s[1][1]))
	{
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&s[1][2],&s[1][3],&s[2][1],&s[2][2],&s[2][3],&s[3][1],&s[3][2],&s[3][3]);
		ans=0;
		int i,j;
		ll sum=0;
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				sum+=s[i][j];
			}
		}
		
		ll mn=9999999999;
		char c[3];//printf("%I64d",mn);
		//printf("\t%I64d\n",sum-s[1][1]-s[2][3]-s[3][2]);
		if((sum-s[1][1]-s[2][3]-s[3][2])<mn)
		{
			mn=sum-s[1][1]-s[2][3]-s[3][2];
			c[0]='B',c[1]='C',c[2]='G';
			//printf("\t%d\n",sum-s[1][1]-s[2][3]-s[3][2]); 
		}
		if(sum-s[1][1]-s[2][2]-s[3][3]<mn)
		{
			mn=sum-s[1][1]-s[2][2]-s[3][3];
			c[0]='B',c[1]='G',c[2]='C'; 
		} 
		if(sum-s[1][3]-s[2][1]-s[3][2]<mn)
		{
			mn=sum-s[1][3]-s[2][1]-s[3][2];
			c[0]='C',c[1]='B',c[2]='G'; 
		} 
		if(sum-s[1][3]-s[2][2]-s[3][1]<mn)
		{
			mn=sum-s[1][3]-s[2][2]-s[3][1];
			c[0]='C',c[1]='G',c[2]='B'; 
		} 
		if(sum-s[1][2]-s[2][1]-s[3][3]<mn)
		{
			mn=sum-s[1][2]-s[2][1]-s[3][3];
			c[0]='G',c[1]='B',c[2]='C'; 
		} 
		if(sum-s[1][2]-s[2][3]-s[3][1]<mn)
		{
			mn=sum-s[1][2]-s[2][3]-s[3][1];
			c[0]='G',c[1]='C',c[2]='B'; 
		} 
		printf("%s %lld\n",c,mn);
	}
	
    return 0;
}
