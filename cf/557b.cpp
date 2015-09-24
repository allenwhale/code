#include <bits/stdc++.h>
using namespace std;
double c[200010];
int main(){
    int N;
    double W;
    scanf("%d %lf",&N,&W);
    for(int i=0;i<N*2;i++){
        scanf("%lf",&c[i]);
    }
    sort(c,c+2*N);
    printf("%lf\n", min(min(W,c[0]*3*(double)N),c[N]/2.0*3.0*(double)N));
    return 0;
}

