#include <iostream>
#include <stdio.h>
int end[400020];
struct Node
{
	int sum,l,r,mid; 
};
Node seg[1000040];
int s[400020];
Node add(int f,int t,int index)
{
	Node work;
	work.l=f,work.r=t,work.mid=(f+t)/2;
	if(f==t)
	{
		end[f]=index;
		work.sum=s[f];
		return work;
	}
	int mid=(f+t)/2;
	seg[index*2]=add(f,mid,index*2);
	seg[index*2+1]=add(mid+1,t,index*2+1);
	work.sum=seg[index*2].sum+seg[index*2+1].sum;
	return work;
}
int find(int f,int t,int index)
{
	//printf("   %d %d %d\n",index,seg[index].l,seg[index].r);
	int l=seg[index].l,r=seg[index].r;
	//if(l>t||r<f)return 0;
	if(f==l&&t==r)return seg[index].sum;
	int mid=seg[index].mid;
	if(t<=mid)return find(f,t,index*2);
	if(f>=mid+1)return find(f,t,index*2+1);
	return find(f,mid,index*2)+find(mid+1,t,index*2+1);
}
void change(int n,int a)
{
	int index=end[n];
	int pre=s[n];
	s[n]=a;
	seg[index].sum=a;
	index>>=1;
	while(index>0)
	{
		seg[index].sum=seg[index*2].sum+seg[index*2+1].sum;
		index>>=1;
	}
	return;
}
int main()
{
	int N;
	int num=0;
	while(scanf("%d",&N))
	{
		if(N==0)break;
		if(num)printf("\n");
		printf("Case %d:\n",++num);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
		}
		seg[1]=add(0,N-1,1);;
//		for(int i=1;i<2*N;i++)
//		{
//			printf("index %d f %d t %d sum %d\n",i,seg[i].l,seg[i].r,seg[i].sum);
//		}
		getchar();
		char ss[30];
		while(gets(ss))
		{
			if(ss[0]=='E')break;
			char c;
			int a,b;
			sscanf(ss,"%c %d %d",&c,&a,&b);
			if(c=='M')
			{
				printf("%d\n",find(a-1,b-1,1)); 
			}
			else if(c=='S')
			{
				change(a-1,b);
			}
		}
	}
//	while(1);
    return 0;
}
