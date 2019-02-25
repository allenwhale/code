#include <bits/stdc++.h>
using namespace std;
int check(int div, int mod, int n, int k){
    if (mod >= k) return INT_MAX;
    int x = div * k + mod;
    return x;
}
int main(){
    int N, K;

    scanf("%d%d", &N, &K);
    int ans = INT_MAX;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ans = min(ans, check(i, N / i, N, K));
            ans = min(ans, check(N / i, i, N, K));
        }
    }
    printf("%d\n", ans);
    return 0;
}
