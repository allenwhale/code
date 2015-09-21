#include <stdio.h>
#include <string.h>
char s[10000];
int w[30],n,sum;
bool dp[210];
int main()
{
	char a[10];
	gets(a);
	int t;
	sscanf(a,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		gets(s);
		char *ptr=strtok(s," ");
		n=0;
		sum=0;
		while(ptr!=NULL)
		{
			sscanf(ptr,"%d",&w[n]);
			//printf("%s\n",ptr);
			sum+=w[n++];
			ptr=strtok(NULL," ");
		}
		//printf("F");
		memset(dp,false,sizeof(dp));
		dp[0]=true;
		//printf("k");
		if(sum%2==0)
		{
			sum/=2;
			for(int i=0;i<n;i++)
			{
				//printf("%d\n",i);
				for(int j=sum;j>=w[i];j--)
				{
					if(dp[j-w[i]])
					{
						dp[j]=true;
					}
				}
			}
		}
		if(dp[sum])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
    return 0;
}
