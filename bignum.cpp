#include <stdio.h>
#include <string.h>
int swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void print(int *a,int lena)
{
	int i;
	for(i=0;i<lena;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int cmp(int *a,int *b,int lena,int lenb)
{
	if(lena>lenb)return true;
	else if(lenb>lena)return false;
	int i;
	for(i=0;i<lena;i++)
	{
		if(a[i]>b[i])return true;
		else if(a[i]<b[i])return false;
	}
	return true;
}
int eql(int *a,int *b,int st,int ed)
{
	int i,j;
	memset(a,0,sizeof(a));
	for(i=0,j=st-1;j<ed;i++,j++)
	{
		a[i]=b[j];
	}
	return ed-st+1;
}
int mlt10(int *a,int b,int lena)
{
	a[lena]=b;
	return lena+1;
}
int add(int *a,int *b,int lena,int lenb)
{
	int i,j;
	for(i=lenb-1,j=lena-1;i>=0;i--,j--)
	{
		a[j]+=b[i];
	}
	for(i=lena-1;i>0;i--)
	{
		if(a[i]>9)
		{
			a[i-1]++;
			a[i]-=10;
		}
	}
	if(a[0]>9)
	{
		for(i=lena-1;i>=0;i--)
		{
			swap(&a[i],&a[i+1]);
		}
		a[0]=1;
		a[1]-=10;
		lena++;
	}
	return lena;
}
int mns(int *a,int *b,int lena,int lenb)
{
	int i,j;
	for(i=lenb-1,j=lena-1;i>=0;i--,j--)
	{
		a[j]-=b[i];
	}
	for(i=lena-1;i>0;i--)
	{
		if(a[i]<0)
		{
			a[i-1]--;
			a[i]+=10;
		}
	}
	while(a[0]<=0&&lena>0)
	{
		for(i=0;i>lena;i++)
		{
			swap(&a[i],&a[i+1]);
		}
		lena--;
	}
	return lena;
}
int dvs_1(int *a,int b,int lena)
{
	int pre=0,i;
	for(i=0;i<lena;i++)
	{
		int tmp=a[i]+10*pre;
		a[i]=tmp/b;
		pre=tmp%b;
	}
	while(a[0]==0)
	{
		for(i=0;i<lena;i++)
		{
			swap(&a[i],&a[i+1]);
		}
		lena--;
	}
	return lena;
}
int mlt_1(int *a,int b,int lena)
{
	int i;
	int c[1000]={0};
	for(i=0;i<lena;i++)
	{
		c[i]=a[i]*b;
	}
	for(i=lena-1;i>0;i--)
	{
		if(c[i]>9)
		{
			c[i-1]+=c[1]/10;
			c[i]=c[i]%10;
		}
	}
	while(c[0]>9)
	{
		lena++;
		for(i=lena-2;i>=0;i--)
		{
			swap(&c[i],&c[i+1]);
		}
		c[0]=c[1]/10;
		c[1]=c[1]%10;
	}
	eql(a,c,1,lena);
	return lena;
}
int mlt(int *a,int *b,int lena,int lenb)
{
	int c[1000]={0};
	int i,j;
	int lenc=lena+lenb;
	for(i=0;i<lenb;i++)
	{
		for(j=0;j<lena;j++)
		{
			c[i+j]+=a[j]*b[i];
		}
	}
	for(i=lenc-1;i>0;i--)
	{
		c[i-1]+=c[i]/10;
		c[i]=c[i]%10;
	}
	while(c[0]>9)
	{
		for(i=lenc;i>0;i--)
		{
			swap(&c[i],&c[i-1]);
		}
		lenc++;
		c[0]=c[1]/10;
		c[1]=c[1]%10;
	}
	for(i=0;i<lenc;i++)
	{
		a[i]=c[i];
	}
	return lenc;
}
int dvs(int *a,int *b,int lena,int lenb)
{
	int c[1000];
	int cc;
	int tmp[1];
	int lenc=0;
	int i,j;
	int now[1000];
	int use[1000];
	int lenn=0,lenu;
	memset(c,0,sizeof(c));
	memset(now,0,sizeof(now));
	memset(use,0,sizeof(use));
	for(i=0;i<lena;i++)
	{
		tmp[0]=a[i];
		lenn=mlt10(now,a[i],lenn);
		lenu=lenb;
		cc=0;
		int temp[1000],lent=0;
		memset(temp,0,sizeof(temp));
		for(j=0;j<10;j++)
		{
			lenu=eql(use,b,1,lenb);
			lenu=mlt_1(use,j,lenu);
			if(cmp(now,use,lenn,lenu))
			{
				cc=j;
				lent=eql(temp,use,1,lenu);
			}
			else break;
		}
		lenn=mns(now,temp,lenn,lent);
		c[i]=cc;
		lenc++;
	}
	while(c[0]==0)
	{
		for(i=0;i<lenc;i++)
		{
			swap(&c[i],&c[i+1]);
		}
		lenc--;
	}
	eql(a,c,1,lenc);
	return lenc;
}
int main()
{
    return 0;
}
