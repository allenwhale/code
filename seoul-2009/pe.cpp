#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int N, M;
    scanf("%d%d", &N, &M);
    int now = 0;
    for(int i = 1 ; i <= N ; i++){
        now = (now + M) % i;
        printf("  %d\n", now);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}
