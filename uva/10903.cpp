#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,i,q=0;
	while(1)
	{
		
		scanf("%d",&n);
		if(n==0)break;
		scanf("%d",&m);
		int nc=m*n*(n-1)/2;
		int w[110],l[110];
		memset(w,0,sizeof(w));
		memset(l,0,sizeof(l));
		for(i=1;i<=nc;i++)
		{
			int s1,s2;
			char p1[10],p2[10];

			scanf("%d %s %d %s",&s1,p1,&s2,p2);
			//printf("\t%c %c\n",p1[0],p2[0]);
			
			if(p1[0]==p2[0])continue;
			else if(p1[0]=='r'&&p2[0]=='p')
			{	
				w[s2]++;
				l[s1]++;
			}
			else if(p1[0]=='p'&&p2[0]=='r')
			{
				w[s1]++;
				l[s2]++;				
			}
			else if(p1[0]=='r'&&p2[0]=='s')
			{
				w[s1]++;
				l[s2]++;				
			}
			else if(p1[0]=='s'&&p2[0]=='r')
			{
				w[s2]++;
				l[s1]++;				
			}
			else if(p1[0]=='p'&&p2[0]=='s')
			{
				w[s2]++;
				l[s1]++;				
			}
			else if(p1[0]=='s'&&p2[0]=='p')
			{
				w[s1]++;
				l[s2]++;				
			}
		}
		//printf("%d",w[1]);
		if(q!=0)printf("\n");
		q++;
		for(i=1;i<=n;i++)
		{
			//printf("%d\t%d\n",w[i],l[i]);
			if(w[i]+l[i]==0)
			{
				printf("-\n");
				continue;
			}
			printf("%.3lf\n",(double)w[i]/((double)w[i]+(double)l[i]));
		}
	}
    return 0;
}
