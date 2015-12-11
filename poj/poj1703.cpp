//#include <bits/stdc++.h>
#include <stdio.h>
//using namespace std;
#define I(n) ((n)+N)
int p[200010];
int N, M;
void init(){
    for(int i=0;i<=2*N;i++)
        p[i] = i;
}
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge(int a, int b){
    p[find(b)] = find(a);
}
void Solve(){
    scanf("%d%d", &N, &M);
    init();
    for(int i=0;i<M;i++){
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        a--, b--;
        if(op[0] == 'D'){
            merge(a, I(b));
            merge(I(a), b);
        }else if(op[0] == 'A'){
            if(find(a) == find(b))
                printf("In the same gang.\n");
            else if(find(a) == find(I(b)))
                printf("In different gangs.\n");
            else printf("Not sure yet.\n");
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
        Solve();
    return 0;
}
