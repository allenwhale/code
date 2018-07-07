#include <bits/stdc++.h>
using namespace std;
int P[100];
void Solve(){
    int N;
    scanf("%d", &N);
    for(int i = N ; i >= 0 ; i--){
        scanf("%d", &P[i]); 
    }
    int now = 1;
    for(int i = 1 ; i < N ; i++){
        if(now == 0) now = 1;
        else if(P[i] + i + 1 == 0) now = 0;
        else now = 1;
    }
    if(now == 0)printf("0\n");
    else if(N % 2 == 0){
        printf("0\n");
    }else{
        printf("1\n0.0\n");
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
