#include <stdio.h>
#include <string.h>
#include <math.h>
char n_15[]="0123456789ABCDEF";
int n_16[2000];

int main()
{
	n_16[(int)'0']=0;
n_16['1']=1;
n_16['2']=2;
n_16['3']=3;
n_16['4']=4;
n_16['5']=5;
n_16['6']=6;
n_16['7']=7;
n_16['8']=8;
n_16['9']=9;
n_16['A']=10;
n_16['B']=11;
n_16['C']=12;
n_16['D']=13;
n_16['E']=14;
n_16['F']=15;
	char s[100];
	int k,i;
	while(1)
	{
		gets(s);
		if(s[0]=='-')break;
		if(s[1]=='x')
		{
			char ss[100];
			int len=strlen(s);
			for(i=len-1;i>1;i--)
			{
				ss[len-i-1]=s[i];
			}
			k=0;
			for(i=0;i<len-2;i++)
			{
				//char m[1];
//				int n;
//				m[0]=ss[i];
//				sscanf(m,"%d",&n);
				k=k+pow(16,i)*n_16[ss[i]];
			}
			printf("%d\n",k);
		}
		else
		{
			int l=0;
			sscanf(s,"%d",&k);
			if(k!=0)printf("0x");
			else printf("0");
			int ss[100];
			while(k!=0)
			{
				ss[l]=k%16;
				k=k/16;
				l++;
			}
			char h[100];
			for(i=0;i<l;i++)
			{
				printf("%c",n_15[ss[l-1-i]]);
			}
			printf("\n");
			
		}
	}
    return 0;
}
