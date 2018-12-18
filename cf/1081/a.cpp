#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;

    scanf("%d", &N);
    if (N <= 2) {
        printf("%d\n", N);
        return 0;
    }
    for (int i = N - 1; i >= 1; i--) {
        if (N % i != 0) {
            printf("%d\n", N - i);
            return 0;
        }
    }
    return 0;
}
