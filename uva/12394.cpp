#include <bits/stdc++.h>
using namespace std;

void Solve(int K, int N){
    char c[N][100];
    memset(c, 0, sizeof(c));
    unordered_set<int> P[N];
    vector<bool> bad(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%s", c[i]);
        for(int j = 0 ; j < K ; j++){
            int x;
            scanf("%d", &x);
            if(P[x - 1].find(i) != P[x - 1].end()){
                bad[x - 1] = true;
            }else{
                P[x - 1].insert(i);
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        if((int)P[i].size() != K){
            bad[i] = true;
        }
        for(auto x : P[i]){
            if(!strcmp(c[x], c[i])){
                bad[i] = true;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < N ; i++)
        ans += bad[i];
    if(ans == 0)
        printf("NO PROBLEMS FOUND\n");
    else if(ans == 1)
        printf("1 PROBLEM FOUND\n");
    else
        printf("%d PROBLEMS FOUND\n", ans);
}

int main(){
    int K, N;
    while(~scanf("%d%d", &K, &N) && K && N){
        Solve(K, N);
    }
    return 0;
}
