#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int N,M,num[2][1510],n[1510];
char s[15010];
int main()
{
    scanf("%d %d%*c",&N,&M);
    int flag=1,ans=-1;
    for(int i=0;i<N;i++,flag^=1)
    {
        gets(s);
        for(int j=0;j<M;j++)
        {
            if(s[j]=='0')num[flag][j]=0;
            else num[flag][j]=num[flag^1][j]+1;
        }
        memcpy(n,num[flag],4*M);
        sort(n,n+M);
        for(int j=M-1;j>=0&&n[j];j--)
        {
            ans=max(ans,n[j]*(M-j));
        }
    }
    printf("%d\n",ans);
}
