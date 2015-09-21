#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int f[200010];
char in[100010],work[200020];
void change(int len)
{
	int l=len;
	for(int i=0;--len>=0;i++)
	{
		work[i]=in[len];
	}
	for(int i=l,j=0;j<l;i++,j++)
	{
		work[i]=in[j];
	} 
	//strcat(work,in);
}
void failure(int n)
{
	int k=-1;
	f[0]=-1;
	for(int i=1;i<n;i++)
	{
		while(k>=0&&work[k+1]!=work[i])k=f[k];
		if(work[k+1]==work[i])k++;
		f[i]=k;
	}
}

int main()
{
	while(gets(in)!=NULL)
	{
		int n=strlen(in);
		memset(work,0,sizeof(work));
		memset(f,0,sizeof(f));
		change(n);
		//puts(work);
		failure(n*2);
		int t=f[n*2-1];
		printf("%s",in);
		for(int i=t+1;i<n;i++)
		{
			printf("%c",work[i]);
		}
		printf("\n");
	}
    return 0;
}
