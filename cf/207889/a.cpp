#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int ans;
    scanf("%d", &ans);
    for(int i=1;i<N;i++){
        int x;
        scanf("%d", &x);
        ans = __gcd(ans, x);
    }
    printf("%d\n", ans * N);
}
