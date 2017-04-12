#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
int a[MAXN];
vector<pair<int, int>> ed[MAXN];
int ans[MAXN];
int dfs(int x, int d){
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<N;i++){
        int p, w;
        scanf("%d%d", &p, &w);
        p--;
        ed[p].push_back({i, w});
    }
    return 0;
}
