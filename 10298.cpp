#include <cstdio>
#include <cstring>
char s[1000010];
int f[1000010];
int KMP()
{
	memset(f,0,sizeof(f));
	int k=-1;
	f[0]=-1;
	int n=strlen(s);
	for(int i=1;i<n;i++)
	{
		while(k>=0&&s[i]!=s[k+1])k=f[k];
		if(s[k+1]==s[i])k++;
		f[i]=k;
	}
	return k;
}
int main()
{
	while(scanf("%s",s))
	{
		if(strlen(s)==1&&s[0]=='.')break;
		int t=KMP();
		int n=strlen(s);
		if(n%(n-t-1)==0)
		{
			printf("%d\n",n/(n-t-1));
		}
		else
		{
			printf("1\n");
		}
	}
//	while(1);
    return 0;
}
