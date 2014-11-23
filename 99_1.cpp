#include <stdio.h>
#include <string.h>
int s[10010];
int turn(int a)
{
	char ss[10];
	sprintf(ss,"%d",a);
	int i=0;
	while(ss[i])
	{
		a+=ss[i]-'0';
		i++;
	}
	return a;
}
int main()
{
	memset(s,-1,sizeof(s));
	for(int i=1;i<=10000;i++)
	{
		if(s[i]!=-1)continue;
		s[i]=0;
		int tmp=turn(i);
		while(tmp<=10000)
		{
			s[tmp]=1;
			tmp=turn(tmp);
		}
	}
	for(int i=1;i<=10000;i++)
	{
		if(s[i]==0)printf("%d ",i);
	}
	return 0;
}

