#include <bits/stdc++.h>
using namespace std;

int main(){
    double K, P, X;
    scanf("%lf%lf%lf", &K, &P, &X);
    double M = sqrt(K * P / X);
    double ans = 1e15;
    for(int i = (int)max(0.0, M - 2.0) ; i < (int)(M + 2.0) ; i++){
        ans = min(ans, K * P / (double)i + X * (double)i);
    }
    printf("%.3f\n", ans);
    return 0;
}
