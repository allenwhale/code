#include <bits/stdc++.h>
using namespace std;
int Solve(int x){
    if(x == 0) return 0;
    return Solve(x/2) + 1;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        printf("%d\n", Solve(N));
    }
}
