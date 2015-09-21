/*
ID: allenwh1
PROG: friday
LANG: C++
*/
#include <stdio.h>
int y=1900,m=1,d=13;
int N;
int ans[8];
bool leap()
{
	if(y%400==0)return true;
	if(y%4==0&&y%100!=0)return true;
	return false;
}
int add()
{
	if(m==4||m==6||m==9||m==11)
	{
		m++;
		return 30;
	}
	if(m==2&&leap())
	{
		m++;
		return 29;
	}
	if(m==2&&!leap())
	{
		m++;
		return 28;
	}
	if(m==1||m==3||m==5||m==7||m==8||m==10)
	{
		m++;
		return 31;
	}
	if(m==12)
	{
		y++;
		m=1;
		return 31;
	}
}
bool ck()
{
	if(y>1900+N-1)return false;
	return true;
}
int main()
{	
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	scanf("%d",&N);
	while(ck())
	{
		d=d%7;
		ans[d]++;
		d+=add();
	}
	printf("%d %d",ans[6],ans[0]);
	for(int i=1;i<=5;i++)
	{
		printf(" %d",ans[i]);
	}
	printf("\n");
    return 0;  
}
