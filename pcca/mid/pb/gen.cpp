#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    int N = stoi(argv[1]), M = stoi(argv[2]);
    printf("%d %d\n", N, M);
    for(int i=0;i<M;i++)
        printf("%d %d %d\n", rand()%N, rand()%N, rand()%100);
    return 0;
}
