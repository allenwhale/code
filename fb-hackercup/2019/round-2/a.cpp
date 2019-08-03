#include <bits/stdc++.h>
using namespace std;
void Solve() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    int C[3];
    for (int i = 0; i <= K; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        C[i] = (a + b) & 1;
    }
    if (C[1] == C[2] && C[1] == C[0])
        printf("Y\n");
    else
        printf("N\n");
}
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        Solve();
    }
    return 0;
}