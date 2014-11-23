/*
ID: allenwh1
PROG: sort3
LANG: C++
*/
#include <stdio.h>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}
int s[4];
int num[1010];
int N,con=0;
int main()
{
	fin("sort3.in");
	fout("sort3.out");
	s[1]=s[2]=s[3]=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
		s[num[i]]++;
	}
	//printf("%d %d %d\n",s[1],s[2],s[3]);
	for(int i=0;i<s[1];i++)
	{
		if(num[i]!=1)
		{
			bool tf=true;
			con++;
			if(num[i]==2)
			{
				for(int j=s[1];j<s[2]+s[1];j++)
				{
					if(num[j]==1)
					{
						swap(&num[i],&num[j]);
						tf=false;
						break;
					}
				}
			}
			else 
			{
				for(int j=s[1]+s[2];tf&&j<N;j++)
				{
					if(num[j]==1)
					{
						swap(&num[i],&num[j]);
						break;
					}
				}
			}
			
		}
	}
	for(int i=s[1];i<s[2]+s[1];i++)
	{
		if(num[i]!=2)
		{
			con++;
			for(int j=s[2]+s[1];j<N;j++)
			{
				if(num[j]==2)
				{
					swap(&num[i],&num[j]);
					break;
				}
			}
		}
	}
	printf("%d\n",con);
    //while(1);
	return 0;
}
