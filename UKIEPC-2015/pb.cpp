#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
double D[10], O[10];
double ans[10];
int main(){
    int N;
    double G;
    scanf("%d%lf", &N, &G);
    for(int i=0;i<N;i++)
        scanf("%lf%lf", &D[i], &O[i]);
    ans[N] = 0;
    for(int i=N-1;i>=0;i--){
        ans[i] = ans[i + 1] + 2.0 * cos(O[i] / 180.0 * PI) * G * D[i];
    }
    for(int i=0;i<N;i++){
        printf("%.10f\n", sqrt(ans[i]));
    }
    return 0;
}
