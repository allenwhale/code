#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 2 ; i < N ; i++){
        if((N - i) % (i + i - 1) == 0 || N % (i + i - 1) == 0){
            printf("%d %d\n", i, i - 1);
        }
        if(N % i == 0){
            printf("%d %d\n", i, i);
        }
    }
    return 0;
}
