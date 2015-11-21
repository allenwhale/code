#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int N,A,B,K;
int dp[5010][5010]={0};
int sum[5010]={0};
int get(int a,int b){
    return (sum[b]-sum[a]+MOD)%MOD;
}
void calc(int x){
    for(int i=1;i<=N;i++)
        sum[i]=(dp[x][i]+sum[i-1])%MOD;
}
int main(){
    scanf("%d%d%d%d",&N,&A,&B,&K);
    dp[0][A]=1;
    calc(0);
    for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            if(j==B)continue;
            if(j<B){
                int end=B-(abs(B-j)>>1)-1;
                dp[i][j]=(get(0,end)-dp[i-1][j]+MOD)%MOD;
            }else{
                int start=B-(abs(B-j)>>1)+1;
                dp[i][j]=(get(start-1, N)-dp[i-1][j]+MOD)%MOD;
            }
        }
        calc(i);
    }
    printf("%d\n", sum[N]);
    return 0;
}
