/*
ID: allenwh1
PROG: hamming
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <deque>
using namespace std;
#define dqb(a) dq.push_back(a)
#define dqf() dq.front()
#define dqe() dq.back()
#define dqs() dq.size()
#define dqm() dq.empty()
#define dqp() dq.pop_front()
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
deque<int>dq;
int N,B,D;
int hamming(int a,int b)
{
	int c=a^b;
	int d=0;
	while(c>0)
	{
		if(c&1)d++;
		c>>=1;
	}
	return d;
}
int main()
{
	fin("hamming.in");
	fout("hamming.out");
	scanf("%d %d %d",&N,&B,&D);
	dqb(0);
	for(int i=1;i<N;i++)
	{
		int last=dqe();
		
		for(int j=last+1;;j++)
		{
			bool tf=true;
			for(int k=0;k<dqs()&&tf;k++)
			{
				if(hamming(dq[k],j)<D)tf=false;
			}
			if(tf)
			{
				dqb(j);
				break;
			}
		}
	}
	int n=0;
	while(!dqm())
	{
		n++;
		if(n==1)printf("%d",dqf());
		else printf(" %d",dqf());
		dqp();
		if(n==10)printf("\n"),n=0;
	}
	if(n!=0)printf("\n");
    return 0;
}
