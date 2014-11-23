#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
bool num[1000010];
bool gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return (a+b)==1;
}
int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		memset(num,false,sizeof(num));
		int cnt=0;
		for(int i=1;i*i<=N;i++)
		{
			for(int j=i+1;j*i*2<=N;j++)
			{
				//printf("%d %d\n",i,j);
				if(!gcd(i,j))continue;
				int a=-i*i+j*j,b=2*i*j,c=i*i+j*j;
				if(c>N)break;
				int ma=a,mb=b,mc=c;
				while(mc<=N)
				{
					num[ma]=num[mb]=num[mc]=true;
					ma+=a,mb+=b,mc+=c;
				}
				if((i&1)^(j&1))cnt++;
			}
		}
		int cnt2=0;
		for(int i=1;i<=N;i++)
			if(!num[i])cnt2++;//,printf(" %d\n",i);;
		printf("%d %d\n",cnt,cnt2);
	}
	return 0;
}

