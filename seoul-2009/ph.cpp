#include <bits/stdc++.h>
using namespace std;
int c[100010][2];
int p[100010], g[100010], mx[1000010], mn[1000010];
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge(int a, int b){
    int new_g = g[find(a)] + g[find(b)];
    int new_mx = max(mx[find(a)], mx[find(b)]);
    int new_mn = min(mn[find(a)], mn[find(b)]);
    p[find(a)] = find(b);
    g[find(a)] = new_g;
    mx[find(a)] = new_mx;
    mn[find(a)] = new_mn;
}
#define lb(x) ((x) & -(x))
struct Bit{
    int N;
    vector<int> d;
    Bit(int n=0): N(n), d(n + 10){}
    int query(int x){
        int res = 0;
        while(x){
            res += d[x];
            x -= lb(x);
        } 
        return res;
    }
    void update(int x, int v){
        while(x <= N){
            d[x] += v;
            x += lb(x);
        }
    }
};
void Solve(){
    int N;
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        p[i] = i, g[i] = 1;
    for(int i = 0 ; i < N ; i++){
        scanf("%d%d", &c[i][0], &c[i][1]);
        for(int j = 0 ; j < 2 ; j++)
            c[i][j] = c[i][j] * 2 + 1;
        mx[i] = mn[i] = c[i][1];
    }
    int Q;
    scanf("%d", &Q);
    Bit city(2000010), state(2000010);
    while(Q--){
        char cmd[10];
        scanf("%s", cmd);
        if(cmd[0] == 'r'){
            int a, b;
            scanf("%d%d", &a, &b);
            if(find(a) == find(b))continue;
            state.update(mn[find(a)], -1);
            state.update(mx[find(a)], 1);
            state.update(mn[find(b)], -1);
            state.update(mx[find(b)], 1);
            city.update(mn[find(a)], -g[find(a)]);
            city.update(mx[find(a)], g[find(a)]);
            city.update(mn[find(b)], -g[find(b)]);
            city.update(mx[find(b)], g[find(b)]);
            merge(a, b);
            state.update(mn[find(a)], 1);
            state.update(mx[find(a)], -1);
            city.update(mn[find(a)], g[find(a)]);
            city.update(mx[find(a)], -g[find(a)]);
        }else{
            int c;
            scanf("%d.5", &c);
            c = c * 2 + 2;
            printf("%d %d\n", state.query(c), city.query(c));
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Solve();
    }
    return 0;
}

