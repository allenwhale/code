#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int N;
    scanf("%d", &N);
    vector<int> vc[2], S;
    for(int i = 0 ; i < N ; i++){
        int x;
        scanf("%d", &x);
        vc[i & 1].push_back(x);
    }
    sort(vc[0].begin(), vc[0].end());
    sort(vc[1].begin(), vc[1].end());
    for(int i = 0 ; i < N / 2 ; i++){
        S.push_back(vc[0][i]);
        S.push_back(vc[1][i]);
    }
    if(N & 1)S.push_back(vc[0].back());
    for(int i = 0 ; i < (int)S.size() - 1 ; i++){
        if(S[i] > S[i + 1]){
            printf("%d\n", i);
            return;
        }
    }
    printf("OK\n");
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1 ; i <= T ; i++){
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
