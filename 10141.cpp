#include <stdio.h>
int main()
{
	int n,m;
	char name[1010][90];
	char s[90];
	int i;
	int q=0;
	while(~scanf("%d %d",&n,&m))
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		q++;
		getchar();
		for(i=1;i<=n;i++)
		{
			gets(s);
		}
		int nmin=99999999,rmax=-1;
		double pmin=99999999.9;
		for(i=0;i<m;i++)
		{
			double price;
			int r;
			gets(name[i]);
			scanf("%lf %d",&price,&r);
			getchar();
			for(int j=1;j<=r;j++)
			{
				gets(s);
			}
			
			if(r>rmax)
			{
				rmax=r;
				nmin=i;
				pmin=price;
			}
			else if(r==rmax)
			{
				if(price<pmin)
				{
					pmin=price;
					nmin=i;
				}
			}
		}
		if(q>1)printf("\n");
		printf("RFP #%d\n%s\n",q,name[nmin]);
	}
    return 0;
}
