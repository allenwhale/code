#include <bits/stdc++.h>
using namespace std;
void gen0(int T, int N){
    printf("%d\n", T);
    int d = N / T;
    while(T--){
        printf("%d\n", max(10, N - d * T));
        int r = rand() % 26;
        for(int i=0;i<N;i++)
            printf("%c", 'a' + r);
        puts("");
        for(int i=0;i<N;i++)
            printf("%c", 'a' + r);
        puts("");
    }
}

void gen1(int T, int N){
    printf("%d\n", T);
    char s[N+10];
    int d = N / T;
    while(T--){
        printf("%d\n", max(10, N - d * T));
        for(int i=0;i<N;i++)
            s[i] = 'a' + rand() % 26;
        for(int t=rand()%N, i=0;i<N;i++)
            printf("%c", s[(i+t)%N]);
        puts("");
        for(int t=rand()%N, i=0;i<N;i++)
            printf("%c", s[(i+t)%N]);
        puts("");
    }
}

void gen2(int T, int N){
    printf("%d\n", T);
    int d = N / T;
    while(T--){
        printf("%d\n", max(10, N - d * T));
        char s[10];
        for(int i=0;i<2;i++)
            s[i] = rand() % 26 + 'a';
        for(int i=0;i<N;i++)
            printf("%c", s[i < (N/2-T)]);
        puts("");
        for(int i=0;i<N;i++)
            printf("%c", s[i < (N/2-T)]);
        puts("");
    }
}

void gen3(int T, int N){
    printf("%d\n", T);
    while(T--){
        printf("%d\n", 10);
        char s[2];
        s[0] = rand() % 26 + 'a';
        s[1] = rand() % 25 + 'a';
        for(int i=0;i<N;i++)
            printf("%c", s[rand()%2]);
        puts("");
        for(int i=0;i<N;i++)
            printf("%c", s[rand()%2]);
        puts("");
    }
}

void gen4(int T, int N){
    printf("%d\n", T);
    int cnt = 2;
    while(T--){
        printf("%d\n", cnt++);
        for(int i=0;i<N;i++)
            printf("%c", rand()%cnt + 'a');
        puts("");
        for(int i=0;i<N;i++)
            printf("%c", rand()%cnt + 'a');
        puts("");
    }
}

int main(int argc, char ** argv){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    int T = stoi(argv[1]), N = stoi(argv[2]), gen = stoi(argv[3]);
    if(gen == 0) gen0(T, N);
    if(gen == 1) gen1(T, N);
    if(gen == 2) gen2(T, N);
    if(gen == 3) gen3(T, N);
    if(gen == 4) gen4(T, N);
}
