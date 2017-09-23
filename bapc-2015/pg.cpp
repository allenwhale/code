#include <bits/stdc++.h>
using namespace std;


void Solve(){
    int N;
    scanf("%d", &N);
    double mx = 0;
    int mx_id = 0;
    for(int i = 0 ; i < N ; i++){
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        double x = max(0., b / (2. * a));
        double y = -a * x * x + b * x + c;
        if(y > mx){
            mx = y;
            mx_id = i;
        }
    }
    printf("%d\n", mx_id + 1);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
