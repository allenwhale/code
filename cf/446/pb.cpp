#include <bits/stdc++.h>
using namespace std;
int L[1000010];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &L[i]);
    }
    int kill = N;
    int ans = N;
    for(int i = N - 1; i >= 0 ; i--){
        if(kill <= i)ans--;
        kill = min(kill, i - L[i]);
    }
    printf("%d\n", ans);
    return 0;
}
