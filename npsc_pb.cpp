#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
struct road
{
	int len;
	int num;
//	road(int tl,int tn)
//	{
//		len=tl;
//		num=tn;
//	}
	bool operator < (const road &n) const
	{
		return n.len<len;
	}
};
road Road(int tl,int tn)
{
	road tmp;
	tmp.len=tl,tmp.num=tn;
	return tmp;
}
road s[1000000];
int vis[1000000];
int p[1000000];
int main()
{
//	freopen("pb.in","r",stdin);
//	freopen("pb.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		memset(p,false,sizeof(p));
		ll all=0;
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			s[j]=Road(tmp,j);
			all+=(ll)tmp;
		}
		all*=2;
		all+=(ll)(n-1)*5;
		sort(s,s+n);
		ll ans=0;
		int N=0;
		//ll ans=0;
		for(int j=0;s[j].len>15&&j<n;j++)
		{
			if(s[j].num<3)continue;
			N++;
			p[s[j].num]=true;
			int cnt=0;
			for(int k=0;k<n;k++)
			{
				if(p[k])cnt-=3;
				if(cnt<0)break;
				if(cnt<6)cnt++;
			}
			if(cnt<0)
			{
				N--;
				p[s[j].num]=false;
			}
			else
			{
				ans+=s[j].len-15;
			}
		}
		//printf("%I64d %I64d\n",all,ans);
		printf("%I64d\n",all-ans);
	}
	return 0;
}

