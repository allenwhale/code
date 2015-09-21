#include <stdio.h>
char s[1000010];
int sum[1000010];
int toint(char a)
{
	return a-'0';
}
void presum()
{
	int i=1;
	sum[0]=toint(s[0]);
	while(s[i]!='\0')
	{
		sum[i]=sum[i-1]+toint(s[i]);
		i++;
	}
}
int range(int a,int b)
{
	if(b<=0)return sum[0];
	return sum[b]-sum[a-1];
}
int main()
{
	int j=1;
	while(gets(s)!=NULL)
	{
		printf("Case %d:\n",j);
		j++;
		presum();
		int n;
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
		{
			int f,t;
			if(f>t)int tmp=f,f=t,t=tmp;
			scanf("%d %d",&f,&t);
			int ans=range(f,t);
			bool tf;
			if(ans==0)tf=true;
			else if(ans==t-f+1)tf=true;
			else tf=false;
			if(tf)printf("Yes\n");
			else printf("No\n");
		}
		getchar();
	}
    return 0;
}
