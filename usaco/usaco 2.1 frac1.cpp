/*
ID: allehwh1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define db double
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
struct state
{
	int a,b;
	state(int ta,int tb)
	{
		a=ta,b=tb;
	}
	bool operator < (const state &n) const
	{
		if((db)a/(db)b>(db)n.a/(db)n.b)return true;
		return false;
	}
};
priority_queue<state>pq;
int gcd(int a,int b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
int N;
int main()
{
	fin("frac1.in");
	fout("frac1.out");
	scanf("%d",&N);
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(gcd(i,j)==1)pq.push(state(j,i));
		}
	}
	printf("0/1\n");
	while(!pq.empty())
	{
		state tmp=pq.top();
		pq.pop();
		printf("%d/%d\n",tmp.a,tmp.b);
	}
	printf("1/1\n");
	//while(1);
    return 0;
}
