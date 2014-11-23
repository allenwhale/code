#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MS(a,b) memset(a,b,sizeof(a))
#ifdef _DEBUG
#define __lld "%I64d"
#else
#define __lld "%lld"
#endif 
using namespace std;
char s[100];
long long dp[100][100];
long long find(int x,int y)
{
    long long &tmp=dp[x][y];
    //printf("%d %d\n",x,y);
    //system("pause");
    if(tmp!=-1)return tmp;
    if(x>y)return tmp=0;
    else if(x==y)return tmp=1;
    else if(s[x]==s[y])return tmp=find(x+1,y)+find(x,y-1)+1;
    else return tmp=find(x+1,y)+find(x,y-1)-find(x+1,y-1);
}
int main()
{
    int _t;
    scanf("%d%*c",&_t);
    while(_t--)
    {
        gets(s);
        int len=strlen(s);
        MS(dp,-1ll);
        /*for(int i=0;i<len;i++)
        {
            for(int j=i;j<len;j++)
            {
                if(i==j)dp[i][j]=0;
                else if(s[i]==s[j])dp[i][j]=dp[i-1][j]+dp[][]+1;
            }
        }*/
        printf(__lld"\n",find(0,len-1));
    }
}
