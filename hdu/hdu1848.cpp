#include <bits/stdc++.h>
using namespace std;

int fib[1000];
int sg[1010];

int getSg(int x){
    if(sg[x] != -1)return sg[x];
    vector<int> res;
    for(int i=0;fib[i]<=x;i++){
        res.push_back(getSg(x - fib[i]));
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    int ans = 0;
    for(int i : res){
        if(ans == i)ans++;
        else break;
    }
    return sg[x] = ans;
}

int main(){
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    fib[0] = 1;
    fib[1] = 2;
    for(int i=2;;i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] > 1000)break;
    }
    int N, M, P;
    while(scanf("%d%d%d", &N, &M, &P), N || M || P){
        int ans = getSg(N) ^ getSg(M) ^ getSg(P);
        if(ans)
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}
