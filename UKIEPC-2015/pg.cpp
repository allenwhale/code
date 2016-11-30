#include <bits/stdc++.h>
using namespace std;
char name[10][30];
int w[10];
int c[10];
bool dp[1010][610];
int dpget[1010][610][10];
int main(){
    double dM, dU;
    int D;
    scanf("%lf%lf%d", &dM, &dU, &D);
    int M = int((dM * 100.0) + 1e-5);
    int U = int((dU * 30.0) + 1e-5);
    for(int i=0;i<D;i++){
        scanf("%s", name[i]);
        int s;
        scanf("%d", &s);
        int a;
        scanf("%*d/%d", &a);
        w[i] = (s * 30) / a;
        double tmp;
        scanf("%lf", &tmp);
        c[i] = int((tmp * 100.0) + 1e-5);
    }
    //for(int i=0;i<D;i++){
        //printf("%s %d %d\n", name[i], w[i], c[i]);
    //}
    memset(dp, 0, sizeof(dp));
    memset(dpget, 0, sizeof(dpget));
    dp[0][0] = true;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=U;j++){
            for(int k=0;k<D;k++){
                if(i >= c[k] && j >= w[k] && dp[i - c[k]][j - w[k]]){
                    dp[i][j] = true;
                    for(int l=0;l<D;l++)
                        dpget[i][j][l] = dpget[i - c[k]][j - w[k]][l];
                    dpget[i][j][k]++;
                }
            }
        }
    }
    if(dp[M][U]){
        for(int i=0;i<D;i++){
            if(dpget[M][U][i]){
                printf("%s %d\n", name[i], dpget[M][U][i]);
            }
        }
    }else{
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
