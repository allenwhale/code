/*
ID: allenwh1
PROG: crypt1
LANG: C++
*/
#include <stdio.h>
int s[10];
int N;
bool in(int x)
{
	for(int i=0;i<N;i++)
	{
		if(s[i]==x)return true;
	}
	return false;
}
bool ck(int t)
{
	while(t>0)
	{
		int tmp=t%10;
		if(!in(tmp))return false;
		t/=10;
	}
	return true;
}
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&s[i]);
	}
	int c=0;
	for(int i=100;i<1000;i++)
	{
		for(int j=10;j<100;j++)
		{
			int t1=j%10,t2=(j/10)%10;
			int c1=t1*i,c2=t2*i,c3=i*j;
			if(c1/1000>0||c2/1000>0||i*j/10000>0)continue;
			if(ck(i))
			{
				if(ck(j))
				{
					if(ck(c1))
					{
						if(ck(c2))
						{
							if(ck(c3))
							{
								//printf("%d %d %d %d\n",i,j,c1,c2);
								c++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n",c);
	//while(1);
    return 0;
}
