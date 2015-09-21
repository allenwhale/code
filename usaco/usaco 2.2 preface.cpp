/*
ID: allenwh1
PROG: preface
LANG: C++
*/
#include <stdio.h>
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
int N;
int I=0,V=0,X=0,L=0,C=0,D=0,M=0;
int main()
{
	fin("preface.in");
	fout("preface.out");
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		int tmp=i;
		int n1=tmp%10;
		tmp/=10;
		int n2=tmp%10;
		tmp/=10;
		int n3=tmp%10;
		tmp/=10;
		int n4=tmp%10;
		if(n1==0);
		else if(n1==1)I++;
		else if(n1==2)I+=2;
		else if(n1==3)I+=3;
		else if(n1==4)I++,V++;
		else if(n1==5)V++;
		else if(n1==6)V++,I++;
		else if(n1==7)V++,I+=2;
		else if(n1==8)V++,I+=3;
		else if(n1==9)X++,I++;
		if(n2==0);
		else if(n2==1)X++;
		else if(n2==2)X+=2;
		else if(n2==3)X+=3;
		else if(n2==4)X++,L++;
		else if(n2==5)L++;
		else if(n2==6)L++,X++;
		else if(n2==7)L++,X+=2;
		else if(n2==8)L++,X+=3;
		else if(n2==9)C++,X++;
		if(n3==0);
		else if(n3==1)C++;
		else if(n3==2)C+=2;
		else if(n3==3)C+=3;
		else if(n3==4)D++,C++;
		else if(n3==5)D++;
		else if(n3==6)D++,C++;
		else if(n3==7)D++,C+=2;
		else if(n3==8)D++,C+=3;
		else if(n3==9)M++,C++;
		if(n4==0);
		else if(n4==1)M++;
		else if(n4==2)M+=2;
		else if(n4==3)M+=3;
	}
	if(I!=0)printf("I %d\n",I);
	if(V!=0)printf("V %d\n",V);
	if(X!=0)printf("X %d\n",X);
	if(L!=0)printf("L %d\n",L);
	if(C!=0)printf("C %d\n",C);
	if(D!=0)printf("D %d\n",D);
	if(M!=0)printf("M %d\n",M);
    return 0;
}
