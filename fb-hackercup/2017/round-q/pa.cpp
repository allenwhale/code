#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x) * (x))

void Solve(){
    int p, x, y;
    scanf("%d%d%d", &p, &x, &y);
    if(sqr(x - 50) + sqr(y - 50) > sqr(50)){
        printf("white\n");
        return;
    }
    double cosT = (double)(0 * (x - 50) + 50 * (y - 50)) / (50. * sqrt(sqr(x - 50) + sqr(y - 50)));
    double T;
    if(x >= 50 && y >= 50){
        T = acos(cosT);
    }else if(x >= 50 && y <= 50){
        T = acos(cosT);
    }else if(x <= 50 && y <= 50){
        T = acos(cosT) + acos(-1) / 2.;
    }else{
        T = acos(-1) * 2. - acos(cosT);
    }
    if(T <= acos(-1) * 2. * (double)p / 100.){
        printf("black\n");
    }else{
        printf("white\n");
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}
