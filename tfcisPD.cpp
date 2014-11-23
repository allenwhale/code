#include <stdio.h>
#include <iostream>
#include <queue>
#include <time.h>
struct f
{
	int a;
	f(int ta)
	{
		a=ta;
	}
	bool operator <(const f &n)const
	{
		if(a<n.a)return true;
		return false;
	}
};
struct b
{
	int a;
	b(int ta)
	{
		a=ta;
	}
	bool operator <(const b &n)const
	{
		if(a<n.a)return false;
		return true;
	}
};
using namespace std;
int main()
{
	freopen("D_Large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int st=clock();
	int N;
	int lenf=0,lenb=0;
	priority_queue<f>pqf;
	priority_queue<b>pqb;
	pqf.push(f(0));
	pqb.push(b(999999));
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int s;
		scanf("%d",&s);
		if(s>pqb.top().a)
		{
			lenb++;
			pqb.push(b(s));
		}
		else
		{
			lenf++;
			pqf.push(f(s));
		}
		if(lenf-lenb==2)
		{
			lenf--;
			lenb++;
			pqb.push(b(pqf.top().a));
			pqf.pop();
		}
		else if(lenb-lenf==2)
		{
			lenf++;
			lenb--;
			pqf.push(f(pqb.top().a));
			pqb.pop();
		}
		int mid;
		if(lenf>lenb)
		{
			f tmp=pqf.top();
			mid=tmp.a;
		}
		else if(lenb>lenf)
		{
			b tmp=pqb.top();
			mid=tmp.a;
		}
		else
		{
			f tmp1=pqf.top();
			b tmp2=pqb.top();
			mid=(tmp1.a+tmp2.a)/2;
		}
		printf("%d\n",mid);
		
	}
	printf("%d",clock()-st);
	while(1);
    return 0;
}
