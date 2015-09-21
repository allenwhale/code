#include <stdio.h>
int n;
int toi(char s)
{
	return s-'0';
}
int a(int s)
{
	int b=s*2;
	int tmp=b/10;
	return b-9*tmp;
}
int main()
{
	
	scanf("%d",&n);
	int i;
	int a1,a2;
	char s[20];
	getchar(); 
	for(i=1;i<=n;i++)
	{		
		gets(s);
		//printf("%s",s);
		a1=0;
		a2=0;
		a2=a(toi(s[0]))+a(toi(s[2]))+a(toi(s[5]))+a(toi(s[7]))+a(toi(s[10]))+a(toi(s[12]))+a(toi(s[15]))+a(toi(s[17]));
		a1=toi(s[1])+toi(s[3])+toi(s[6])+toi(s[8])+toi(s[11])+toi(s[13])+toi(s[16])+toi(s[18]);
		//printf("%d\n",a1+a2);
		if((a1+a2)%10==0)
		{
			printf("Valid\n");
		}
		else 
		{
			printf("Invalid\n");
		}
	}
    return 0;
}
