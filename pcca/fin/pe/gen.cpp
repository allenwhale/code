#include <bits/stdc++.h>
using namespace std;
void gen0(int N){
    int M = N - 1;
    printf("%d %d\n", N, M);
    for(int i=0;i<N-1;i++)
        printf("%d %d\n", i, i + 1);
}
void gen1(int N){
    int M = N - 1;
    printf("%d %d\n", N, M);
    for(int i=1;i<N;i++)
        printf("%d %d\n", 0, i);
}
void gen2(int N){
    int M = N / 10;
    printf("%d %d\n", N, M);
    for(int i=0;i<M;i++)
        printf("%d %d\n", rand() % N, rand() % N);
}
void gen3(int N){
    int M = (rand() & 1) ? N / (rand() % N) : 0;
    printf("%d %d\n", N, M);
    for(int i=0;i<M;i++){
        int a = rand() % N;
        printf("%d %d\n", a, a);
    }
}
void gen4(int N){
    int M = (rand() & 1) ? N * 50 : N / 100;
    printf("%d %d\n", N, M);
    for(int i=0;i<M;i++)
        printf("%d %d\n", rand() % N, rand() % N);
}
int main(int argc, char **argv){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    int type = stoi(argv[1]), T = stoi(argv[2]), N = stoi(argv[3]);
    printf("%d\n", T);
    while(T--){
        if(type == 0)gen0(N);
        if(type == 1)gen1(N);
        if(type == 2)gen2(N);
        if(type == 3)gen3(N);
        if(type == 4)gen4(N);
    }
}
