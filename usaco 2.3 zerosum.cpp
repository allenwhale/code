/*
ID: allenwh1
PROG: zerosum
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
#include <math.h>
#include <algorithm>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
deque<int>dq;
int N;
//0 ' '
//1 '+'
//2 '-'
int rev(int x)
{
	int tmp=0;
	for(int i=1;i<=N;i++)
	{
		tmp+=(x%3)*pow(3,N-i);
		x/=3;
	}
	return tmp;
}
void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
bool cmp(int a,int b)
{
	a=rev(a);
	b=rev(b);
	return a<b;
}
int s[10]={0,1,2,3,4,5,6,7,8,9};
int ss[10]={0,1,2,3,4,5,6,7,8,9};
int main()
{
	fin("zerosum.in");
	fout("zerosum.out");
	scanf("%d",&N);
	int all=1;
	for(int i=1;i<N;i++)
	{
		all*=3;
	}
	for(int i=0;i<all;i++)
	{
		int nn=N;
		memcpy(s,ss,sizeof(ss));
		int sum=1;
		int tmp=i;
		int ans[10];
		int n=0;
		int num=1;
		bool tf=true;
		for(int j=2;j<=N;j++)
		{
			int t=tmp%3;
			tmp/=3;
			ans[n++]=t; 
		}
		for(int j=0,k=1;j<N-1;j++,k++)
		{
			if(ans[j]==0)
			{
				s[k]=s[k]*10+s[k+1];
				for(int l=k+1;l<=N;l++)swap(s[l],s[l+1]);
				k--;
			}			
		}
		sum=s[1];
		tmp=i;
		for(int j=2;j<=nn;j++)
		{
			int t=tmp%3;
			tmp/=3;
			if(t==0)j--,nn--;
			else if(t==1)sum+=s[j];
			else if(t==2)sum-=s[j];
		}
		if(sum==0)dq.push_back(i);
	}
	sort(dq.begin(),dq.end(),cmp);
	while(!dq.empty())
	{
		int tmp=dq.front();
		dq.pop_front();
		int n=1;
		printf("%d",n++);
		for(int i=1;i<N;i++)
		{
			//printf("%d ",tmp%3);
			int t=tmp%3;
			if(t==0) printf("%c",' ');
			else if(t==1) printf("%c",'+');
			else printf("%c",'-');
			printf("%d",n++);
			tmp/=3;
		}
		printf("\n");
	}
    return 0;
}
