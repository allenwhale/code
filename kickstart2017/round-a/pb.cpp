#include <bits/stdc++.h>
using namespace std;
char s[2][2010];
int dp[2010][2010];
void Solve(){
    scanf("%s%s", s[0] + 1, s[1] + 1); 
    int len[2];
    len[0] = strlen(s[0] + 1);
    len[1] = strlen(s[1] + 1);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=len[0];i++){
        if(s[0][i] == '*')
            dp[i][0] = 1;
        else break;
    }
    for(int i=1;i<=len[1];i++){
        if(s[1][i] == '*')
            dp[0][i] = 1;
        else break;
    }
    for(int i=1;i<=len[0];i++){
        for(int j=1;j<=len[1];j++){
            if(s[0][i] == s[1][j]){
                dp[i][j] |= dp[i - 1][j - 1]; 
            }
            if(s[0][i] == '*'){
                int cnt = 0;
                for(int k=j;k>=0&&j-k<=4+cnt&&!dp[i][j];k--){
                    cnt += s[1][k] == '*';
                    dp[i][j] |= dp[i - 1][k];
                }
            }
            if(s[1][j] == '*'){
                int cnt = 0;
                for(int k=i;k>=0&&i-k<=4+cnt&&!dp[i][j];k--){
                    cnt += s[0][k] == '*';
                    dp[i][j] |= dp[k][j - 1];
                }
            }
        }
    }
    printf("%s\n", dp[len[0]][len[1]] ? "TRUE" : "FALSE");
}
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        Solve();
    }
}
