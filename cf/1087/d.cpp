#include <bits/stdc++.h>
using namespace std;
int cnt[200010] = { 0 };
int main(){
    int S, N;

    scanf("%d%d", &N, &S);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        cnt[a]++;
        cnt[b]++;
    }
    int leaves = 0;
    for (int i = 1; i <= N; i++) {
        leaves += cnt[i] == 1;
    }
    printf("%.10f\n", 2.0 * S / (double)leaves);
    return 0;
}
