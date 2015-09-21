#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
char s[100][100];
char s1[20010],s2[20010];
int x,y;
int len1,len2;
void to(char c)
{
	if(c=='E')
	{
		y++;
		return;
	}
	if(c=='W')
	{
		y--;
		return;
	}
	if(c=='S')
	{
		x++;
		return;
	}
	if(c=='N')
	{
		x--;
		return;
	}
}
int LCStoLIS()
{
	deque<int>p1[200];
	for(int i=1;i<=len1;i++)
	{
		p1[(int)s1[i]].push_back(i);
	}
	deque<int>LIS;
	LIS.push_back(-1);
	for(int i=1;i<=len2;i++)
	{
		for(int j=p1[(int)s2[i]].size()-1;j>=0;j--)
		{
			int n=p1[(int)s2[i]][j];
			if(n>LIS.back())
			{
				LIS.push_back(n);
			}
			else
			{
				*lower_bound(LIS.begin(),LIS.end(),n)=n;
			}
		}
	}
	return LIS.size()-1;
}
int main()
{
	int t;
	char tmp[20010];
	gets(tmp);
	sscanf(tmp,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		gets(tmp);
		int n,m;
		sscanf(tmp,"%d %d",&n,&m);
		for(int j=0;j<n;j++)
		{
			gets(s[j]);
		}
		gets(tmp);
		int st;
		sscanf(tmp,"%d %d %d",&st,&x,&y);
		x--,y--;
		gets(tmp);
		s1[len1=1]=s[x][y];
		for(int j=0;j<st;j++)
		{
			to(tmp[j]);
			s1[len1=j+2]=s[x][y];
		}
		gets(tmp);
		sscanf(tmp,"%d %d %d",&st,&x,&y);
		x--,y--;
		gets(tmp);
		s2[len2=1]=s[x][y];
		for(int j=0;j<st;j++)
		{
			to(tmp[j]);
			s2[len2=j+2]=s[x][y];
		}
		int LCS=LCStoLIS();
		printf("Case %d: %d %d\n",i,len1-LCS,len2-LCS);
	}
    return 0;
}
