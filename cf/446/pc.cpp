#include <bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &a[i]);
    }
    int gcd = a[0];
    for(int i = 0 ; i < N ; i++){
        gcd = __gcd(gcd, a[i]);
    }
    if(gcd != 1){
        printf("-1\n");
        return 0;
    }
    int one = 0;
    for(int i = 0 ; i < N ; i++){
        one += a[i] == 1;
    }
    if(one){
        printf("%d\n", N - one);
        return 0;
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N - i - 1 ; j++){
            a[j] = __gcd(a[j], a[j + 1]);
            if(a[j] == 1){
                printf("%d\n", N + i);
                return 0;
            }
        }
    }
    return 0;
}
