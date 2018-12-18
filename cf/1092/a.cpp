#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d%d", &N, &K);
        for (int j = 0; j < N; j++) {
            printf("%c", 'a' + j % K);
        }
        printf("\n");
    }
    return 0;
}
