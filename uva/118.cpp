#include <stdio.h>
#include <string.h>
typedef long long ll;
ll dy[4]={1,0,-1,0};
ll dx[4]={0,1,0,-1};
ll ss[1000][2];
int sn=0;
int tow(int t,char c)
{
	if(c=='R')t++;
	else t--;
	if(t<0)t+=4;
	else if(t>3)t-=4;
	return t;
}
ll find(ll *x,ll *y,int t)
{
	int i;
	int xx=*x-dx[t],yy=*y-dy[t];
	for(i=0;i<sn;i++)
	{
		if(xx==ss[i][0]&&yy==ss[i][1])
		{
			*x-=dx[t];
			*y-=dy[t];
			return 0;
		}
	}
	return 1;
}
int main()
{
	ll x,y;
	scanf("%lld %lld",&x,&y);
	char t;
	ll fx,fy;
	char s[110];
	while(~scanf("%lld %lld %c",&fx,&fy,&t))
	{
		int tt;
		if(t=='N')tt=0;
		else if(t=='E')tt=1;
		else if(t=='S')tt=2;
		else tt=3;
		getchar();
		gets(s);
		int len=strlen(s);
		int i=0;
		bool tf=true;
		char a;
		while(s[i]!='\0')
		{
			if(s[i]=='F')
			{
				fx+=dx[tt];
				fy+=dy[tt];
				
				//printf("x%lld y%lld\n",fx,fy);
			}
			else tt=tow(tt,s[i]);
			if(fx>x||fy>y||fx<0||fy<0)
			{
				if(find(&fx,&fy,tt)==0)
				{
					i++;
					continue;
				}
				if(tt==0)a='N';
				else if(tt==1)a='E';
				else if(tt==2)a='S';
				else a='W';
				ss[sn][0]=fx-dx[tt];
				ss[sn][1]=fy-dy[tt];
				sn++;
				printf("%lld %lld %c LOST\n",fx-dx[tt],fy-dy[tt],a);
				tf=false;
				break;
			}
			i++;
		}		
		if(tt==0)a='N';
		else if(tt==1)a='E';
		else if(tt==2)a='S';
		else a='W';
		if(tf)printf("%lld %lld %c\n",fx,fy,a);
	}
    return 0;
}
