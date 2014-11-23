#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int w[2005],dp[2005][10005],pre[2005][10005],all[2005];

void backtrack(int x,int y){
    if(x==0)    return;
    backtrack(x-1,pre[x][y]);
    if(y==pre[x][y])    printf("port\n");
    else    printf("starboard\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   
    int T,re = 0;
    cin >> T;
    for(int N,L;T-- && cin>>L;){
        if(re==1)    printf("\n");    re = 1;
        L *= 100;
        N = 1;
        for(int len;cin >> len,len;)
            w[N++] = len;
        all[0] = 0;
        for(int i=1;i<=N;i++)
            all[i] = all[i-1]+w[i];
        memset(dp,0,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        dp[0][0] = 1;
        for(int i=1;i<N;i++){
            for(int j=L;j>=w[i];j--){
                if(dp[i-1][j-w[i]]==1){
                    dp[i][j] = 1;
                    pre[i][j] = j-w[i];
                }
            }
            for(int j=L;j>=0;j--){
                if(dp[i-1][j]==1){
                    int another = all[i-1]-j;
                    if(another+w[i]<=L){
                        dp[i][j] = 1;
                        pre[i][j] = j;
                    }
                }
            }
        }
        int maxi = 0, mv = 0;
        for(int i=1;i<N;i++)
            for(int j=0;j<=L;j++)
                if(dp[i][j]==1)
                    if(i>maxi)
                        maxi = i, mv = j;
        printf("%d\n",maxi);
        backtrack(maxi,mv);
    }
   
    return 0;
}
