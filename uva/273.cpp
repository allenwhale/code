#include <iostream>
#include <complex>
#include <cstdio>
#include <cstring>
using namespace std;
typedef complex<int> cd;
#define sc scanf
#define pr printf
#define mx(a,b,c,d) (max(max(a,max(c,d)),a))
#define mn(a,b,c,d) (min(min(min(c,d),b),a))
bool tf[15][15];
struct line
{
	cd a,b;
}l[15];
bool ck(int n1,int n2)
{
	cd a1=l[n1].a,a2=l[n1].b;
	cd b1=l[n2].a,b2=l[n2].b;
	if(!(max(a1.real(),a2.real())>=min(b1.real(),b2.real())&&min(a1.real(),a2.real())<=max(b1.real(),b2.real())))return false;
	if(!(max(a1.imag(),a2.imag())>=min(b1.imag(),b2.imag())&&min(a1.imag(),a2.imag())<=max(b1.imag(),b2.imag())))return false;
	cd tmp1,tmp2,tmp3,tmp4;
	tmp1=a1-b1;
	tmp2=a2-b1;
	tmp3=a1-b2;
	tmp4=a2-b2;
	cd t1,t2;
	t1=conj(tmp1)*(tmp2);
	t2=conj(tmp3)*(tmp4);
	if(t1.imag()*t2.imag()>0)return false;
	tmp1=b1-a1;
	tmp2=b2-a1;
	tmp3=b1-a2;
	tmp4=b2-a2;
	t1=conj(-tmp1)*(-tmp2);
	t2=conj(-tmp3)*(-tmp4);
	if(t1.imag()*t2.imag()>0)return false;
	return true;
}
int main()
{
	int N;
	sc("%d",&N);
	for(int i=0;i<N;i++)
	{
		memset(tf,false,sizeof(tf));
		if(i)pr("\n");
		int a,b,c,d;
		int n;
		sc("%d",&n);
		for(int j=0;j<n;j++)
		{
			sc("%d %d %d %d",&a,&b,&c,&d);
			l[j].a=cd (a,b);
			l[j].b=cd (c,d);
		}
		int n1,n2;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				tf[j][k]=ck(j,k);
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					if(j==l||j==k)continue;
					if(k==l)tf[k][l]=true;
					if(tf[k][j]&&tf[j][l])tf[k][l]=true;
				}
			}
		}
		while(sc("%d %d",&n1,&n2))
		{
			if(n1==0&&n2==0)break;
			if(tf[n1-1][n2-1]||n1==n2)pr("CONNECTED\n");
			else pr("NOT CONNECTED\n");
		}
	}
	return 0;
}
