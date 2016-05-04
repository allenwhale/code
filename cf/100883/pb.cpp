#include <bits/stdc++.h>
using namespace std;
int Solve(){
    int N;
    scanf("%d", &N);
    int minx = 10000, miny = 10000, maxx = -100000, maxy = -10000;
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            int x, y;
            scanf("%d%d", &x, &y);
            minx = min(x, minx);
            miny = min(y, miny);
            maxx = max(x, maxx);
            maxy = max(y, maxy);
        }
    }
    return (maxx - minx) * (maxy - miny);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        printf("%d\n", Solve());
    }
    return 0;
}
