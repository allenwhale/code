#include<stdio.h>
void push_ud(int num[],int len,int a)
{
	num[len+1]=a;
	int s=len+1;
	int p=s/2;
	while(s>=2&&num[s]<num[p])
	{
        int temp=num[s];
		num[s]=num[p];
		num[p]=temp;
		s=p;
		p=s/2;
	}
	return;
}
int pop_ud(int num[],int len)
{
	int k=num[1];
	num[1]=num[len];
	int s=1;
	int p=s*2;
	while(p<=len-1&&s<=len-1)
	{
		if(num[p]>num[p+1]&&p<len-1)p++;
		if(num[s]>num[p])
		{
			int temp=num[s];
			num[s]=num[p];
			num[p]=temp;
		}
		s=p;
		p=s*2;
	}
	return k;
}
int main()
{
	int N;
	while(scanf("%d",&N))
	{
		if(N==0)return 0;
		int number[5010];
		int i,k;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&k);
			push_ud(number,i-1,k);
		}
		int a,b,ans,cost=0;
		while(N>=2)
		{
			a=pop_ud(number,N);
			N--;
			b=pop_ud(number,N);
			N--;
			ans=a+b;
			cost=cost+ans;
			push_ud(number,N,ans);
			N++;
		}
		printf("%d\n",cost);
	}
	return 0;
}
