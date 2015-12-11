#include <stdio.h>

const int N = 30010;
int p[N], sz[N], u[N];
void init(){
    for(int i=0;i<N;i++)
        p[i] = i, sz[i] = 1, u[i] = 0;
}
int find(int x){
    if(x != p[x]){
        int tp = find(p[x]);
        u[x] += u[p[x]];
        p[x] = tp;
    }
    return p[x];
}
void merge(int a, int b){
    int fa = find(a), fb = find(b);
    if(fa == fb) return ;
    p[fa] = fb;
    u[fa] += sz[fb];
    sz[fb] += sz[fa];
}
int main(){
    init();
    int P;
    scanf("%d", &P);
    while(P--){
        char op[2];
        int a, b;
        scanf("%s", op);
        if(op[0] == 'M'){
            scanf("%d%d", &a, &b);
            merge(a, b);
        }else if(op[0] == 'C'){
            scanf("%d", &a);
            printf("%d\n", u[find(a), a]);
        }
    }
    return 0;
}
