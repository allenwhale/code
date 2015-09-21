#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int dp[110][110];
char s1[110],s2[110];
void print(int a,int b)
{
    //printf(" %d %d\n",a,b);
    //system("pause");
    if(!a||!b)
    {
        if(a)
        {
            while(a)
            {
                printf("D%c%02d",s1[a],a);
                a--;
            }
        }
        else if(b)
        {
            while(b)
            {
                printf("I%c01",s2[b]);
                b--;
                //b--;
            }
        }
    }
    else if(s1[a]==s2[b])print(a-1,b-1);
    else
    {
        if(dp[a][b]==dp[a][b-1]+1)printf("I%c%02d",s2[b],a+1),print(a,b-1);
        else if(dp[a][b]==dp[a-1][b]+1)printf("D%c%02d",s1[a],a),print(a-1,b);
        else if(dp[a][b]==dp[a-1][b-1]+1)printf("C%c%02d",s2[b],a),print(a-1,b-1);
    }
}
int main()
{
    while(~scanf("%s",s1+1)&&strcmp(s1+1,"#")!=0&&~scanf("%s",s2+1))
    {
        int len1=strlen(s1+1),len2=strlen(s2+1);
        for(int i=0;i<=len1;i++)
        {
            for(int j=0;j<=len2;j++)
            {
                if(!i||!j)dp[i][j]=i+j;
                else if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }/*
        for(int i=0;i<len1;i++,puts(""))
        {
            for(int j=0;j<=len2;j++)
                printf("%d ",dp[i][j]);
        }*/
        print(len1,len2);
        puts("E");
    }
}
