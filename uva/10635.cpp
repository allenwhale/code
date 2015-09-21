#include <stdio.h>
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
#define MAX 250*250+10
int s1[MAX],s2[MAX];
int n,a,b; 
int LCStoLIS()
{
	int p[MAX];
	memset(p,-1,sizeof(p));
	for(int i=0;i<a;i++)
		p[s1[i]]=i;
	deque<int>dq;
	dq.push_back(-1);
	for(int i=0;i<b;i++)
	{
		int n=p[s2[i]];
		if(n==-1)continue;
		if(n>dq.back())
			dq.push_back(n);
		else
			*lower_bound(dq.begin(),dq.end(),n)=n;
	}
	return dq.size()-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{		
		scanf("%d %d %d",&n,&a,&b);
		//printf("%d %d\n",a,b);
		for(int j=0;j<=a;j++)
			scanf("%d",&s1[j]);//,printf("%d\n",s1[j]);
		for(int j=0;j<=b;j++)
			scanf("%d",&s2[j]);//,printf("%d\n",s2[j]);
		a++,b++;
		int ans=LCStoLIS();
		printf("Case %d: %d\n",i,ans);
	}
    return 0;
}
