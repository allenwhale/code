#include <stdio.h>
#include <string.h>
#define R(x) (x+N)
#define MAXN 10010
int p[MAXN*2];
int N;
void init()
{
	for(int i=0;i<=2*N;i++)p[i]=i;
}
int find(int x)
{
	//printf(" %d\n",x);
	return x==p[x]?x:p[x]=find(p[x]); 
}
void U(int a,int b)
{
//	printf("U %d %d %d %d\n",a,find(a),b,find(b));
	p[a]=b;
}

int main()
{
	//memset(p,0,sizeof(p));
	scanf("%d",&N);
	init();
	
	int a,b,c;
	while(~scanf("%d %d %d",&c,&a,&b)&&c)
	{
		int aa=find(a),bb=find(b);
		int ra=find(a+N),rb=find(b+N);
		//printf("    %d %d %d %d\n",a,ra,b,rb);
		if(c==1)//sf
		{
			if(aa==rb)puts("-1");
			else U(aa,bb),U(ra,rb);
		}
		else if(c==2)//se
		{
			if(aa==bb)puts("-1");
			else U(aa,rb),U(bb,ra);
		}
		else if(c==3)//af
		{
			if(aa==bb)puts("1");
			else puts("0");
		}
		else if(c==4)//ae
		{
			if(aa==rb)puts("1");
			else puts("0");
		}
		//print();
	}
	return 0;
}
