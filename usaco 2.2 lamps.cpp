/*
ID: allenwh1
PROG: lamps
LANG: C++
*/
#include <stdio.h>
#include <iostream>
#include <deque>
#include <algorithm>
#include <map>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
using namespace std;
map<int,int>mp;
deque<int>dq;
const int n1=63,n2=21,n3=42,n4=9;
int c,N;
int muston=0,mustoff=63;
int light=63;
int rev(int x)
{
	int tmp=0;
	int n=0;
	while(x>0)
	{
		tmp+=(x&1)<<(6-n);
		n++;
		x>>=1;
	}
	return tmp;
}
bool cmp(int a,int b)
{
	a=rev(a);
	b=rev(b);
	return b>a;
}
void DFS(int state,int r)
{
	if(r==0)
	{
		if(((state&muston)==muston)&&((state|mustoff)==mustoff))
		{
			dq.push_back(state);
		}
		return;
	}
	light^=n1;
	DFS(light^n1,r-1);
	light^=n1;
	light^=n2;
	DFS(light^n2,r-1);
	light^=n2;
	light^=n3;
	DFS(light^n3,r-1);
	light^=n3;
	light^=n4;
	DFS(light^n4,r-1);
	light^=n4;
}
int main()
{
	fin("lamps.in");
	fout("lamps.out");
	scanf("%d %d",&N,&c);
	int n;
	while(scanf("%d",&n))
	{
		if(n==-1)break;
		n--;
		muston|=1<<((n%6));
	}
	int f;
	while(scanf("%d",&f))
	{
		if(f==-1)break;
		f--;
		mustoff^=1<<((f%6));
	}
	//printf("%d %d\n",muston,mustoff);
	//while(c>4)c-=2;
	DFS(light,c>4?4:c);
	if(dq.size()==0)printf("IMPOSSIBLE\n");
	else 
	{
		sort(dq.begin(),dq.end(),cmp);
		int pre=1e9;
		while(!dq.empty())
		{
			int tmp=dq.front();
			dq.pop_front();
			if(pre==tmp)continue;
			pre=tmp;
			for(int i=0;i<N;i++)
			{
				if(tmp&(1<<(i%6)))printf("1");
				else printf("0");
			}
			printf("\n");
		}
	}//while(1);
    return 0;
}
