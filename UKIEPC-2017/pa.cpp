#include <bits/stdc++.h>
using namespace std;
int h[30], r[30], t[30];
bool ok(int R, int T, int x){
    if(R < T)return R < x && x < T;
    else return R < x || x < T;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d%d%d", &h[i], &r[i], &t[i]);
    }
    for(int i = 0 ; i <= 1825 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            bool tf = true;
            int hh = i * 100 + j;
            for(int k = 0 ; k < N ; k++){
                if(ok(r[k], t[k], hh % h[k])){
                    tf = false;
                }
            }
            if(tf){
                printf("%d\n", hh);
                return 0;
            }
        }
    }
    printf("impossible\n");
    return 0;
}
