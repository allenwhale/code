#include <bits/stdc++.h>
using namespace std;
vector<int> vc[3010];
int v[3010];
void dfs(int x, int d = 0){
    if(d == 2){
        v[x]++;
        return;
    }
    for(int u: vc[x])
        dfs(u, d + 1);
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        vc[a].push_back(b);
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        memset(v, 0, sizeof(v));
        dfs(i, 0);
        for(int j=1;j<=N;j++)
            if(j != i)
                ans += (v[j] * (v[j] - 1)) >> 1;
    }
    printf("%d\n", ans);
    return 0;
}
