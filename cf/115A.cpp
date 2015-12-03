#include <bits/stdc++.h>
using namespace std;
int p[2010], v[2010];
int dfs(int x){
    if(v[x] != -1) return v[x];
    if(p[x] == -1) return v[x] = 1;
    return v[x] = dfs(p[x]) + 1;
}
int main(){
    memset(v, -1, sizeof(v));
    int N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
        scanf("%d", &p[i]);
    int ans = 0;
    for(int i=1;i<=N;i++)
        ans = max(ans, dfs(i));
    printf("%d\n", ans);
}
