#include <bits/stdc++.h>
using namespace std;
int f[100010];
int main(){
    int N;
    scanf("%d", &N);
    if(N % 4 > 1){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=N/2;i+=2){
        f[i] = i + 1;
        f[i + 1] = N - i + 1;
        f[N - i + 1] = N - i;
        f[N - i] = i;
    }
    if(N & 1)
        f[N / 2 + 1] = N / 2 + 1;
    for(int i=1;i<=N;i++)
        printf("%d ", f[i]);
    puts("");
    return 0;
}
