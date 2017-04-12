#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define lb(x) ((x) & (-(x)))
int bits[MAXN];
void init(){
    memset(bits, 0, sizeof(bits));
}

int sum(int x){
    int res = 0;
    for(; x ; x -= lb(x)){
        res += bits[x];
    }
    return res;
}
void add(int x, int v){
    for(; x < MAXN ; x += lb(x)){
        bits[x] += v;
    }
}

int Solve(int N){
    init();
    add(N + 1, 1);
    for(int i = 0 ; i < N ; i++){
        int l, r;
        scanf("%d%d", &l ,&r);
        l++, r++;
        int target = sum(r) + 1;
        int now = 1, step = N + 1;
        while(step){
            if(sum(now + step / 2) < target){
                now += step / 2 + 1;
                step -= step / 2 + 1;
            }else step /= 2;
        }
        add(l, 1);
        add(now, -1);
    }
    return sum(N);
}

int main(){
    int N;
    while(~scanf("%d", &N) && N)
        printf("%d\n", Solve(N));
    return 0;
}
