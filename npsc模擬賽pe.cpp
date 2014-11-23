#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
map<int,int>mp;
vector<int>vc;
int s[10];
int pr[100000];
int cnt=0;
int len;
int ans=0;
char tmp[10];
bool vis[10];
bool isprime(int x)
{
	for(int i=0;i<cnt&&pr[i]*pr[i]<=x;i++)
	{
		if(x%pr[i]==0)return false;
	}
	return x!=1?true:false;
}
void DFS(int x,int n,int now)
{
	if(x==n)
	{		
		if(isprime(now)&&now)
		{
			//printf("  %d\n",now);
			if(mp.count(now)==0)
			{
				//printf(" %d\n",now);
				mp[now]=1;
				ans++;
			}
		}
		return;
	}
	//int size=vc.size();
	for(int i=0;i<n;i++)
	{
		if(vis[i])continue;
		vis[i]=true;
		DFS(x+1,n,now*10+vc[i]);
		vis[i]=false;
	}
}
int main()
{
	pr[cnt++]=2;
	for(int i=3;i<4000;i+=2)
	{
		bool tf=true;
		for(int j=0;tf&&j<cnt&&pr[j]*pr[j]<=i;j++)
		{
			if(i%pr[j]==0)tf=false;
		}
		if(tf)pr[cnt++]=i;
	}
	int t;
	scanf("%d%*c",&t);
	for(int i=0;i<t;i++)
	{
		ans=0;
		mp.clear();
		gets(tmp);
		len=strlen(tmp);
		for(int j=0;tmp[j];j++)
		{
			s[j]=tmp[j]-'0';
		}
		for(int j=1;j< 1<<len;j++)
		{
			vc.clear();
			int k=0;
			while(k<len)
			{
				if(j&(1<<k))
				{
					vc.push_back(s[k]);
				}
				k++;
			}
			memset(vis,false,sizeof(vis));
			DFS(0,vc.size(),0);
		}
		printf("%d\n",ans);
	}
	return 0;
}

