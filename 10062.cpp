#include <stdio.h>
#include <queue>
#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
map<int,int>mp;
struct st
{
	int a,num;
	st(int ta,int tn)
	{
		a=ta;
		num=tn;
	}
	bool operator <(const st &n)const
	{
		if(num<n.num)return false;
		else if(num==n.num)
		{
			if(a<n.a)return true;
			return false;
		}
		return true;
	}
};
int main()
{
	char s[1010];
	int ss[1010];
	int k[1010];
	int q=0;
	while(gets(s)!=NULL)
	{
		if(q!=0)printf("\n");
		q++;
		mp.clear();
		int len=strlen(s);
		int l=0,i;
		int ans[1010];
		for(i=0;i<len;i++)
		{
			k[i]=(int)s[i];
		}
		//sort(k,k+len);
		for(i=0;i<len;i++)
		{
			if(mp.count(k[i])==0)
			{
				ss[l]=k[i];
				l++;
				mp[k[i]]=0;	
			}
			mp[k[i]]++;
		}
		priority_queue<st>PQ;
		for(i=0;i<l;i++)
		{
			PQ.push(st(ss[i],mp[ss[i]]));
		}
		for(i=0;i<l;i++)
		{
			st a=PQ.top();
			PQ.pop();
			printf("%d %d\n",a.a,a.num);
		}
		
	}
    return 0;
}
