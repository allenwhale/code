#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
struct seg
{
	int l,r;
	int maxhigh;
	int nl,nr;
	seg()
	{
		l=r=nl=nr=maxhigh=-1;
	}
	seg(int _l,int _r,int _h)
	{
		nl=nr=-1;
		l=_l,r=_r,maxhigh=_h;
	}
};
seg S[40010];
int sn;
void init()
{
	S[0]=seg(0,20,0);
	sn=1;
}
void insert(int l,int r,int h,int idx)
{
	int ll=S[idx].l,rr=S[idx].r,mm=(ll+rr)/2;
	printf("ll=%d l=%d rr=%d r=%d maxhigh=%d idx=%d\n",ll,l,rr,r,S[idx].maxhigh,idx);
	//system("pause");
	//if(ll==l&&rr==r)
	if(ll==rr)
	{
		//puts("1");
		S[idx].maxhigh=max(h,S[idx].maxhigh);
		return ;
	}
	else if(r<=mm)
	{
		//puts("2");
		if(S[idx].nl==-1&&S[idx].nr==-1)
		{
			S[idx].nl=sn;
			S[sn++]=seg(ll,mm,S[idx].maxhigh);//l
			S[idx].nr=sn;
			S[sn++]=seg(mm+1,rr,S[idx].maxhigh);//r
		}
		insert(l,r,h,S[idx].nl);
		S[idx].maxhigh=max(max(S[S[idx].nl].maxhigh,S[S[idx].nr].maxhigh),S[idx].maxhigh);
	}
	else if(l>mm)
	{
		//puts("3");
		if(S[idx].nl==-1&&S[idx].nr==-1)
		{
			S[idx].nl=sn;
			S[sn++]=seg(ll,mm,S[idx].maxhigh);//l
			S[idx].nr=sn;
			S[sn++]=seg(mm+1,rr,S[idx].maxhigh);//r
		}
		insert(l,r,h,S[idx].nr);
		S[idx].maxhigh=max(max(S[S[idx].nl].maxhigh,S[S[idx].nr].maxhigh),S[idx].maxhigh);
	}
	else
	{
		//puts("4");
		if(S[idx].nl==-1&&S[idx].nr==-1)
		{
			S[idx].nl=sn;
			S[sn++]=seg(ll,mm,S[idx].maxhigh);//l
			S[idx].nr=sn;
			S[sn++]=seg(mm+1,rr,S[idx].maxhigh);//r
		}
		insert(l,mm,h,S[idx].nl);
		insert(mm+1,r,h,S[idx].nr);
		S[idx].maxhigh=max(max(S[S[idx].nl].maxhigh,S[S[idx].nr].maxhigh),S[idx].maxhigh);
	}
}
int query(int x,int idx)
{
	int ll=S[idx].l,rr=S[idx].r,mm=(ll+rr)/2;
	//printf("%d %d %d %d\n",ll,rr,S[idx].maxhigh,idx);
	//system("pause");
	if((ll==x&&rr==x)||(S[idx].nl==-1&&S[idx].nr==-1))
	{
		return S[idx].maxhigh;
	}
	else if(x<=mm)
	{
		return query(x,S[idx].nl);
	}
	else
	{
		return query(x,S[idx].nr);
	}
}
int main()
{
	int l,r,h;
	int MX=0,MN=10200;
	init();
	while(~scanf("%d %d %d",&l,&h,&r))
	{
		if(l>r)swap(l,r);
		insert(l,r-1,h,0);
		MX=max(MX,r);
		MN=min(MN,l);
	}
	int q;
	while(~scanf("%d",&q))
	{
		printf("%d\n",query(q,0));
	}
	/*
	vector<int>vc;
	int high[10010]={0};
	for(int i=MN;i<=MX;i++)
	{
		high[i]=query(i,0);
	}
	for(int i=MN;i<=MX;i++)
	{
		if(high[i]!=high[i-1])
		{
			vc.push_back(i);
			vc.push_back(high[i]);
		}
	}
	int sz=vc.size();
	for(int i=0;i<sz;i++)
	{
		printf("%d%c",vc[i],i==sz-1?'\n':' ');
	}*/
	return 0;
}

