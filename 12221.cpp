#include <iostream>
#include <complex>
#include <cstdio>
#include <cmath>
using namespace std;
#define cd complex<double>
#define db double
db s[100];
int main()
{
	int N;
	scanf("%d",&N);

	for(int h=0;h<N;h++)
	{
		int n,t;
		db per;
		scanf("%d",&n);
		cd node[100];
		db x,y;
		scanf("%lf %lf",&x,&y);
		node[0]=cd (x,y);
		db xx,yy;
		db all=0.0;
		for(int j=1;j<n;j++)
		{
			scanf("%lf %lf",&xx,&yy);
			node[j]=cd (xx,yy);
			all+=s[j-1]=abs(node[j]-node[j-1]);
			
		}
		for(int j=0;j<n-1;j++)
		{
			s[j]/=all;
		}
		scanf("%d %lf",&t,&per);
		for(int j=0;j<t-1;j++)
		{
			db tmp=per;
			int i=0;
			while(s[i]<tmp)tmp-=s[i++];
			per=tmp/(s[i]);
			cd pres=node[i];
			cd abc=node[0];
			db nl=abs(node[i]-node[i+1]);
			db al=abs(node[0]-node[n-1]);
			db the=arg(node[i]-node[i+1]);
			db athe=arg(node[0]-node[n-1]);
			cd turn(cos(the-athe),sin(the-athe));
			for(int k=0;k<n;k++)
			{
				node[k]-=abc;node[k]*=turn;node[k]*=(nl/al);
				node[k]+=abc;
			}
			cd to=abc-pres;
			for(int k=0;k<n;k++)
			{
				node[k]-=to;
				
			}
		}
        db tmp=per;
		int i=0;
		while(s[i]<tmp)tmp-=s[i++];
		per=tmp/(s[i]);
		cd ans=(per*node[i+1]+(1.0-per)*node[i]);
		printf("(%lf,%lf)\n",ans.real(),ans.imag());
	}
}
