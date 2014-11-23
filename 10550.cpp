#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int s,a,b,c;
	while(1)
	{
		scanf("%d %d %d %d",&s,&a,&b,&c);
		if(a==0&&s==0&&b==0&&c==0)break;
		int k=abs(a-s);
		int l=abs(b-c);
		int n=abs(a-b);
		if(s<a)k=40-k;
		if(a>b)n=40-n;
		if(b<c)l=40-l;
		//printf("\t%d %d %d",k,n,l);
		int ans=360*3+9*(k+n+l);
		printf("%d\n",ans);
	}
    return 0;
}
