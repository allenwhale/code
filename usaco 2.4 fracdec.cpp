/*
ID: allenwh1
PROG: fracdec
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <map>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
map<int,int>mp;
int s[100000];
int sn=0;

int main()
{
	fin("fracdec.in");
	fout("fracdec.out");
	int a,b;
	scanf("%d %d",&a,&b);
	if(a%b==0)
	{
		printf("%d.0\n",a/b);
	}
	else
	{
		printf("%d.",a/b);
		int num=1;
		int aa=a/b;
		if(aa==0)num++;
		while(aa>0)
		{
			num++;
			aa/=10;
		}
		
		a%=b;
		int ft=1e9;
		while(a!=0)
		{
			int n=(a*10)/b;
			int r=a*10;
			
			if(mp.count(r)!=0)
			{
				ft=mp[r];
				break;
			}
			mp[r]=sn;
			s[sn++]=n;
			
			a=r%b;
		}
		
		if(ft==1e9)
		{
			for(int i=0;i<sn;i++)
			{
				printf("%d",s[i]);
				num++;
				if(num==76)
				{
					printf("\n");
					num=0;
				}
			}
		}		
		else
		{
			
			for(int i=0;i<ft;i++)
			{
				printf("%d",s[i]);
				num++;
				if(num==76)
				{
					printf("\n");
					num=0;
				}
			}
			printf("(");
			num++;
			if(num==76)
			{
				printf("\n");
				num=0;
			}
			for(int i=ft;i<sn;i++)
			{
				printf("%d",s[i]);
				num++;
				if(num==76)
				{
					printf("\n");
					num=0;
				}
			}
			printf(")");
		}
		printf("\n");
	}
//	while(1);
    return 0;
}
