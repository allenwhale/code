#include <bits/stdc++.h>
using namespace std;
double dp[40010][10];
char in[20];
double Solve(){
    for(int i=0;i<=40000;i++){
        for(int j=0;j<=10;j++){
            dp[i][j] = 0;
        }
    }
    int H, S;
    scanf("%d%d", &H, &S);
    for(int i=0;i<S;i++){
        int x, y, z = 0;
        scanf("%s", in);
        if(strchr(in, '+')){
            sscanf(in, "%dd%d+%d", &x, &y, &z);
        }else if(strchr(in, '-')){
            sscanf(in, "%dd%d-%d", &x, &y, &z);
            z = -z;
        }else{
            sscanf(in, "%dd%d", &x, &y);
        }
        vector<double> base(x * y + 10);
        for(int j=1;j<=y;j++)
            base[j] = 1.0 / (double)y;
        vector<double> now(x * y + 10);
        now[0] = 1;
        for(int j=0;j<x;j++){
            vector<double> tmp_now(x * y + 10);
            for(int k=0;k<=x*y;k++){
                for(int l=0;l<=x*y;l++){
                    if(k + l <= x * y){
                        tmp_now[k + l] += now[k] * base[l];
                    }
                }
            }
            now = tmp_now;
        }
        for(int j=0;j<=x*y;j++){
            dp[j + z - 10000][i] = now[j];
        }
    }
    vector<double> ans(30000);
    ans[0] = 1;
    for(int i=0;i<S;i++){
        vector<double> tmp_ans(30000);
        for()
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: %f\n", t, Solve());
    }
    return 0;
}
