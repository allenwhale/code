#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef double db;
db solve(int a,int b,int c)
{
	db tmp=sqrt(b*b-4*a*c);
	//printf("  %lf\n",tmp);
	db ans=(tmp-(db)b)/2.0*(db)a;
	return ans;
}
int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		int ans;
		for(int i=1;;i++)
		{
			db n=solve(1,1,-i*i+i-2*N);
			//printf("%d %lf\n",i,n);
			//system("pause");
			if(n!=(db)((int)n))continue;
			int nn=(int)(n+1e-8);
			//printf("sum %d\n",((nn-i+1)*(nn+i)));
			if((nn-i+1)*(nn+i)==2*N)
			{
				ans=n;
				break;
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}

