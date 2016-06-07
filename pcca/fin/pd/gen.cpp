#include <bits/stdc++.h>
using namespace std;
int RAND[500010];
void gen0(int N, int K, int W, int E){
    printf("%d\n", N);
    for(int i=0;i<N;i++)
        printf("%d ", rand() % W);
    puts("");
    for(int i=0;i<N;i++){
        int num = rand() % (min(i, E) + 1);
        E -= num;
        printf("%d", num);
        for(int i=0;i<N;i++)
            RAND[i] = i;
        random_shuffle(RAND, RAND + num);
        while(num--){
            printf(" %d", RAND[num]);
        }
        puts("");
    }
    printf("%d %d\n", K, W);
}
void gen1(int N, int K, int W, int E){
    printf("%d\n", N);
    for(int i=0;i<N;i++)
        printf("%d ", rand() % W);
    puts("");
    for(int i=0;i<N;i++)
        RAND[i] = i;
    for(int i=0;i<N;i++){
        if(i) printf("%d %d\n", 1, i-1);
        else printf("0\n");
    }
    printf("%d %d\n", K, W);
}
void gen2(int N, int K, int W, int E){
    printf("%d\n", N);
    for(int i=0;i<N;i++)
        printf("%d ", rand() % 10);
    puts("");
    for(int i=0;i<N;i++){
        int num = rand() % (min(i, E) + 1);
        E -= num;
        printf("%d", num);
        for(int i=0;i<N;i++)
            RAND[i] = i;
        random_shuffle(RAND, RAND + num);
        while(num--){
            printf(" %d", RAND[num]);
        }
        puts("");
    }
    printf("%d %d\n", K, W);
}
void gen3(int N, int K, int W, int E){
    printf("%d\n", N);
    for(int i=0;i<N;i++)
        printf("%d ", rand() % W);
    puts("");
    for(int i=0;i<N;i++)
        RAND[i] = i;
    for(int i=0;i<N;i++){
        if(i) printf("1 0\n");
        else printf("0\n");
    }
    printf("%d %d\n", K, W);
}
void gen4(int N, int K, int W, int E){
    printf("%d\n", N);
    for(int i=0;i<N;i++)
        printf("%d ", rand() % W);
    puts("");
    for(int i=0;i<N;i++){
        int num = rand() % (min(i, E) + 1);
        E -= num;
        printf("%d", num);
        for(int i=0;i<N;i++)
            RAND[i] = i;
        while(num--){
            printf(" %d", RAND[num]);
        }
        puts("");
    }
    printf("%d %d\n", K, W);
}
int main(int argc, char **argv){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    int type = stoi(argv[1]), T = stoi(argv[2]), N = stoi(argv[3]), K = stoi(argv[4]), W = stoi(argv[5]), E = stoi(argv[6]);
    printf("%d\n", T);
    while(T--){
        if(type == 0) gen0(N, K, W, E);
        if(type == 1) gen1(N, K, W, E);
        if(type == 2) gen2(N, K, W, E);
        if(type == 3) gen3(N, K, W, E);
        if(type == 4) gen4(N, K, W, E);
    }
    fflush(stdout);
    return 0;
}
