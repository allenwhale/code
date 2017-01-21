#include <bits/stdc++.h>
using namespace std;
int w[100010];
struct work{
    int t, d;
    work(int _t=0, int _d=0): t(_t), d(_d){}
    bool operator < (const work &n) const{
        return t < n.t; 
    }
};
int Solve(){
    int L, N, M, D;
    scanf("%d %d %d %d", &L, &N, &M, &D);
    for(int i=0;i<N;i++)
        scanf("%d", &w[i]);
    priority_queue<work> pq;
    int done_N = 0, done_M = 0;
    while(cnt < 2*L){
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
        printf("Case #%d: %d\n", t, Solve());
    return 0;
}
