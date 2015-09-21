#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int len;
struct cn
{
	char n,c;
	cn(char tn,char tc)
	{
		n=tn;
		c=tc;
	}
};
deque<cn>DQ[54];
void prsz()
{
	int i;
	for(i=1;i<=len;i++)
	{
		printf(" %d",DQ[i].size());
	}
	printf("\n");
}
void cl()
{
	int i=1;
	while(i<=len)
	{
		if(DQ[i].size()==0)
		{
			int j;
			for(j=i;j<=len;j++)
			{
				DQ[j].swap(DQ[j+1]);
			}
			//printf("\t%d\n",i);
			len--;
			break;
		}
		i++;
	}
}
void inti()
{
	len=52;
	int i;
	for(i=1;i<=52;i++)
	{
		DQ[i].clear();
	}
}
char s[200],ss[200];
int main()
{

	
	while(1)
	{
		inti();
		gets(s);
		if(s[0]=='#')break;
		int i=0;
		int j=1;
		while(s[i]!='\0')
		{
			DQ[j].push_back(cn(s[i],s[i+1]));
			i+=3;
			j++;
		}
		gets(ss);
		i=0;
		while(ss[i]!='\0')
		{
			DQ[j].push_back(cn(ss[i],ss[i+1]));
			i+=3;
			j++;
		}
		int fr,to;
		while(1)
		{
			fr=0;
			to=0;
			for(i=2;i<=len;i++)
			{
				//cn f=DQ[i].back();
				//cn t=DQ[i-3].back();
				if(i>3)
				{
					
					if(DQ[i].back().n==DQ[i-3].back().n||DQ[i].back().c==DQ[i-3].back().c)
					{
						fr=i;
						to=i-3;
						break;
					}
				}
					//t=DQ[i-1].back();
				if(DQ[i].back().n==DQ[i-1].back().n||DQ[i].back().c==DQ[i-1].back().c)
				{
					fr=i;
					to=i-1;
					break;
				}
			}
			if(fr==to&&to==0)break;
			DQ[to].push_back(DQ[fr].back());
			DQ[fr].pop_back();
			cl();
		}
		if(len==1)printf("%d pile remaining:",len);
		else printf("%d piles remaining:",len);
		prsz();
	}
    return 0;
}
