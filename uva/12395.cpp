#include <bits/stdc++.h>
using namespace std;

double p[4][2];

#define sqr(x) ((x)*(x))
const double eps = 1e-7;
double dist(int a, int b){
    return sqrt(sqr(p[a][0] - p[b][0]) + sqr(p[a][1] - p[b][1]));
}

bool mod(double a, double b){
    return fmod(a, b) < eps || abs(fmod(a, b) - b) < eps;
}
double gcd(double a, double b){
    while((a = mod(a, b)) > eps && (b = mod(b, a)) > eps);
    return a + b;
}
const double PI = acos(-1);
void Solve(){
    double d[3] = {dist(0, 1), dist(1, 2), dist(2, 0)};
    double a[3];
    for(int i = 0 ; i < 3 ; i++){
        a[i] = acos((sqr(d[(i + 1) % 3]) + sqr(d[(i + 2) % 3]) - sqr(d[i])) / (2.0 * d[(i + 1) % 3] * d[(i + 2) % 3])) * 2.0;
    }
    for(int i = 3 ; i <= 1000 ; i++){
        double t = 2.0 * PI  / double(i);
        if(mod(a[0], t) && mod(a[1], t) && mod(a[2], t)){
            printf("%d\n", i);
            break;
        }
    }
}

int main(){
    double x, y;
    while(scanf("%lf%lf", &x, &y) == 2){
        p[0][0] = x, p[0][1] = y;
        for(int i = 1 ; i < 3 ; i++)
            scanf("%lf%lf", &p[i][0], &p[i][1]);

        Solve();
    }
    return 0;
}
