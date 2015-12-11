#include <bits/stdc++.h>
using namespace std;
int p[30010], sz[30010], max_sz;
int N, M;
void init(){
    for(int i=0;i<=N;i++)
        p[i] = i, sz[i] = 1;
    max_sz = 1;
}
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge(int a, int b){
    int fa = find(a), fb = find(b);
    if(fa == fb) return;
    p[fb] = fa;
    sz[fa] += sz[fb];
    sz[fb] = 0;
    max_sz = max(max_sz, sz[fa]);
}
int Solve(){
    scanf("%d%d", &N, &M);
    init();
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
    }
    return max_sz;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        printf("%d\n", Solve());
    return 0;
}
