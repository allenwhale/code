#include<iostream>
#include<stdio.h>  //using double atof(const char *nptr);
#include<string.h>  //using int strlen(char *s);
using namespace std;
int gcd(int, int);
const int decn[10]={(int)1e0,(int)1e1,(int)1e2,
(int)1e3,(int)1e4,(int)1e5,(int)1e6,(int)1e7,(int)1e8,(int)1e9};
int main()
{
   int j,n=0,k_j, deno,nume,red;
   double f;
   char in_f[1000];
   while(~scanf("%d",&j)&&j!=-1)
   {
       n++;
       scanf("%s",in_f);
       k_j=strlen(in_f)-2;
       sscanf(in_f,"%lf",&f);
       f+=0.0000000001;
       if(j)
           deno=int(decn[k_j]-decn[k_j-j]),
           nume=int(decn[k_j]*f-int(decn[k_j-j]*f));
       else
           deno=int(decn[k_j]),
           nume=int(decn[k_j]*f);
       if(nume)
           red=gcd(deno,nume);
       else     
           nume=0,red=1,deno=1;
    	printf("Case %d: %d/%d\n",n,nume/red,deno/red);
   }
   return 0;
}
int  gcd(int a,int b)
{
   while((a%=b)&&(b%=a));
   return a+b;
}
